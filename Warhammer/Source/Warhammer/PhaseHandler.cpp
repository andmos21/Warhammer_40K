// Fill out your copyright notice in the Description page of Project Settings.


#include "PhaseHandler.h"
#include "Enemy.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UPhaseHandler::UPhaseHandler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPhaseHandler::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPhaseHandler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Health>0)
		HandlePhases();

	// ...
}

void UPhaseHandler::HandlePhases()
{
	switch (Phase)
	{
	case 0:
		InitializePhase();
		return;
	case 1:
		ToMovePhase();
		return;
	case 2:
		MovePhase();
		return;
	case 3:
		ToAttackPhase();
		return;
	case 4:
		AttackPhase();
		return;
	case 5:
		ManualPhaseAdvance = false;
		CurrentPhaseName = "EnemyPhase";
		CanMove = true;
		CanAttack = false;
		Phase = 6;
		return;
	case 6:
		return;
	case 7:
		return;
	default:
		return;
	}
}

void UPhaseHandler::InitializePhase()
{
	Phase = 1;
}

void UPhaseHandler::ToMovePhase()
{
	Phase = 2;
	CurrentPhaseName = "MovePhase";
	ManualPhaseAdvance = true;
	CanMove = true;
	CanAttack = false;
	MovementUsed = 0;
}

void UPhaseHandler::MovePhase()
{
	if (MovementUsed >= MovementAllowance)
	{
		CanMove = false;
		
	}
}

void UPhaseHandler::ToAttackPhase()
{
	Phase = 4;
	CurrentPhaseName = "AttackPhase";
	ManualPhaseAdvance = true;
	CanMove = false;
	CanAttack = true;
}

void UPhaseHandler::AttackPhase()
{
	if (TargetEnemy != nullptr && CanAttack)
	{
		int EnemyX = Cast<AEnemy>(TargetEnemy)->GridX;
		int EnemyY = Cast<AEnemy>(TargetEnemy)->GridY;
		int UnitX = GridXLocation;
		int UnitY = GridYLocation;
		
		int xDist = EnemyX - UnitX;
		if (xDist < 0) xDist *= -1;

		int yDist = EnemyY - UnitY;
		if (yDist < 0) yDist *= -1;


		int Distance = xDist + yDist;


		int Range = FMath::RandRange(1, 6);

		if (Range >= Distance)
		{
			TargetEnemy->SetActorLocation({ 0.f, 0.f, 0.f });
		}
		

		CanAttack = false;
	}
}

