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

	HandlePhase();

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

	case 4:
		return;
	default:
		return;
	}
}

void AEnemy::SetupMovePhase()
{
	int TempGoalX = GridX;
	int TempGoalY = GridY;

	unsigned int XDist, YDist;

	bool XSign, YSign;

	//ensures that X distance is positive
	if (GridX >= GridGoalX)
	{
		XDist = GridX - GridGoalX;
		XSign = true;
	}
	else
	{
		XDist = GridGoalX - GridX;
		XSign = false;
	}
	
	//ensures that Y distance is positive
	if (GridY >= GridGoalY)
	{
		YDist = GridY - GridGoalY;
		YSign = true;
	}
	else
	{
		YDist = GridGoalY - GridY;
		YSign = false;
	}


	if (XDist >= YDist)
	{
		XDist = XDist - 1;
		if (XSign)
			GridGoalX = GridGoalX + 1;
		else
			GridGoalX = GridGoalX - 1;

	}
	else
	{
		YDist = YDist - 1;
		if (YSign)
			GridGoalY = GridGoalY + 1;
		else
			GridGoalY = GridGoalY - 1;
	}


	for (int x = 0; x < MovementAllowance; x++)
	{
		if (XDist == 0 && YDist == 0)
			x = MovementAllowance;
		else if (XDist>=YDist)
		{
			XDist = XDist - 1;
			if (XSign)
				TempGoalX = TempGoalX - 1;
			else
				TempGoalX = TempGoalX + 1;	
		}
		else
		{
			YDist = YDist - 1;
			if (YSign)
				TempGoalY = TempGoalY - 1;
			else
				TempGoalY = TempGoalY + 1;
		}
		
	}

	GridGoalX = TempGoalX;
	GridGoalY = TempGoalY;

	Phase++;
}

void AEnemy::MovePhase()
{

}