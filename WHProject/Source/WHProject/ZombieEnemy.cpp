// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieEnemy.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AZombieEnemy::AZombieEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AZombieEnemy::BeginPlay()
{
	Super::BeginPlay();
	LastTickLocation = GetActorLocation();
}

// Called every frame
void AZombieEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	HandlePhase();
}

// Called to bind functionality to input
void AZombieEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AZombieEnemy::HandlePhase()
{
	if (Phase == 1)
	{
		LastTickLocation = GetActorLocation();

		TurnDistanceTravelled = 0.f;

		if (Target != nullptr)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(GetController(), Target->GetActorLocation());

			Phase = 2;
		}
	}
	else if (Phase == 2)
	{
		MovePhase();
	}
	else if (Phase == 3)
	{
		GetCharacterMovement()->StopActiveMovement();

		Phase = 4;
	}
	
}

void AZombieEnemy::MovePhase()
{
	float TravelDistance = FVector::Distance(LastTickLocation, GetActorLocation());

	if (TurnDistanceTravelled + TravelDistance <= MA)
	{

		TurnDistanceTravelled = TurnDistanceTravelled + TravelDistance;


	}
	else
	{
		SetActorLocation(LastTickLocation);

		Phase = 3;
	}

	LastTickLocation = GetActorLocation();
}