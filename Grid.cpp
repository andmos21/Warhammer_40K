// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"

// Sets default values
AGrid::AGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGrid::BeginPlay()
{
	Super::BeginPlay();
	
}

float AGrid::GridHeight() const
{
	float value = NumRows * TileSize;
	return value;
}

float AGrid::GridWidth() const
{
	float value = NumColumns * TileSize;
	return value;
}

/*bool AGrid::TileValid(int Row, int Column)
{
	if (((Row >= 0) && (Row < NumRows)) && ((Column >= 0) && (Column<NumColumns)))
	{
		return true;
	}
	return false;
}*/


// Called every frame
void AGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


