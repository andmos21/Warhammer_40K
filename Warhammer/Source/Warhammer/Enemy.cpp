// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AEnemy::HandlePhase()
{
	switch (Phase)
	{
	case 0:
		return;
	case 1:
		SetupMovePhase();
		return;
	case 2:
		MovePhase();
		return;
	default:
		return;
	}
}

void AEnemy::SetupMovePhase()
{


	Phase = 2;
}

void AEnemy::MovePhase()
{

}