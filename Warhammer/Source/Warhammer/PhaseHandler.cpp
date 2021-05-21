// Fill out your copyright notice in the Description page of Project Settings.


#include "PhaseHandler.h"

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
}

void UPhaseHandler::AttackPhase()
{

}

