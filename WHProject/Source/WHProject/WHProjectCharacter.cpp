// Copyright Epic Games, Inc. All Rights Reserved.

#include "WHProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Components/SphereComponent.h"

AWHProjectCharacter::AWHProjectCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);


	DefaultMaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Create a decal in the world to show the cursor's location
	CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/TopDownCPP/Blueprints/M_Cursor_Decal.M_Cursor_Decal'"));
	if (DecalMaterialAsset.Succeeded())
	{
		CursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	}
	CursorToWorld->DecalSize = FVector(16.0f, 32.0f, 32.0f);
	CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	
}

void AWHProjectCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

	if (CursorToWorld != nullptr)
	{
		if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
		{
			if (UWorld* World = GetWorld())
			{
				FHitResult HitResult;
				FCollisionQueryParams Params(NAME_None, FCollisionQueryParams::GetUnknownStatId());
				FVector StartLocation = TopDownCameraComponent->GetComponentLocation();
				FVector EndLocation = TopDownCameraComponent->GetComponentRotation().Vector() * 2000.0f;
				Params.AddIgnoredActor(this);
				World->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, Params);
				FQuat SurfaceRotation = HitResult.ImpactNormal.ToOrientationRotator().Quaternion();
				CursorToWorld->SetWorldLocationAndRotation(HitResult.Location, SurfaceRotation);
			}
		}
		else if (APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			FHitResult TraceHitResult;
			PC->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
			FVector CursorFV = TraceHitResult.ImpactNormal;
			FRotator CursorR = CursorFV.Rotation();
			CursorToWorld->SetWorldLocation(TraceHitResult.Location);
			CursorToWorld->SetWorldRotation(CursorR);
		}
		
	}
	HandlePhase();
	
}

//A function where it checks which phase the character is on and then acts accordingly.
void AWHProjectCharacter::HandlePhase()
{
	if (Phase == 0)
	{
		GetCharacterMovement()->StopActiveMovement(); //stops the character from moving before enabling movement again.

		StartTurnLocation = GetActorLocation(); //Sets the location for where the character starts the turn, in order to make the reset MA button work

		LastTickLocation = GetActorLocation(); //Sets the Last tick location to where the character remains

		TurnDistanceTravelled = 0.f; //resets MA

		GetCharacterMovement()->MaxWalkSpeed = DefaultMaxWalkSpeed; //turns movement back on



		Phase = 1;
	}


	else if (Phase == 1)
		MovePhase();

	else if (Phase == 2)
	{
		GetCharacterMovement()->MaxWalkSpeed = 0.f;

		Phase = 3;
	}
	
	
	else if (Phase == 5)
		AttackPhase();

	else if (Phase == 6)
	{
		Enemies.Empty();

		Phase = 7;
	}

	else if (Phase == 10)
		Phase = 0;

	//test phase
	else if (Phase == 7)
	{
		FVector Nill = { 0, 0, 0 };
		
		for (auto& EN : Enemies)
		{
			if (EN != this)
			{
				
				EN->SetActorLocation(Nill);
			}
		}
		Phase = 8;
	}
		
	
}

void AWHProjectCharacter::MovePhase()
{
	float TravelDistance = FVector::Distance(LastTickLocation, GetActorLocation());

	if (TurnDistanceTravelled + TravelDistance <= MaxTravelDistance)
	{

		TurnDistanceTravelled = TurnDistanceTravelled + TravelDistance;


	}
	else
	{
		SetActorLocation(LastTickLocation);

		Phase = 2;
	}
	
	LastTickLocation = GetActorLocation();
}

void AWHProjectCharacter::AttackPhase()
{
	if (SearchingForEnemy)
	{
		LookAtTarget();
	}

}

//Function that makes the camera look at an enemy
void AWHProjectCharacter::LookAtTarget()
{
	FVector CameraLocation = TopDownCameraComponent->GetComponentLocation(); //World Location of the camera
	
	FVector EnemyLocation; //World Location of the enemy, determined once the right enemy is picked
	

	//Finds the target out of the array of enemies
	ACharacter* TargetEnemy = nullptr;
	int n = 0;
	for (auto& EN : Enemies)
	{
		if (EnemyInFocus == n)
		{
			TargetEnemy = EN;
		}
		n++;
	}

	if (TargetEnemy)
	{
		EnemyLocation = TargetEnemy->GetActorLocation();

		FVector tRot = EnemyLocation - CameraLocation; //Simple Vector math, to make an FVector that makes the camera look at the enemy

		TopDownCameraComponent->SetWorldRotation(tRot.Rotation());
	}

	SearchingForEnemy = false; //sets Searching for enemy to false, now that it's tried to look for one, so this function won't be called every frame.
}