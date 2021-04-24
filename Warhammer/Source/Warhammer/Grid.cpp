// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"
#include "Math/UnrealMathUtility.h"

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

bool AGrid::TileValid(int Row, int Column)
{
	if (((Row >= 0) && (Row < NumRows)) && ((Column >= 0) && (Column<NumColumns)))
	{
		return true;
	}
	return false;
}

void AGrid::LocationToTile(FVector Location, bool& Valid, int32& Row, int32& Column)
{
	//Rows
	int mRow = FMath::Floor(NumRows * ((Location.X - AActor::GetActorLocation().X) / GridWidth()));
	int mColumn= FMath::Floor(NumColumns * ((Location.Y - AActor::GetActorLocation().Y) / GridHeight()));
	Valid = TileValid(mRow, mColumn);
	Row = mRow;
	Column = mColumn;
}

void AGrid::TileToGridLocation(int32 Row, int32 Column, bool Center, bool& Valid, FVector2D& GridLocation)
{
	Valid = TileValid(Row, Column);
	float TileToGridCenter = Center ? TileSize / 2 : 0.0f;
	GridLocation.X = (Row * TileSize) + AActor::GetActorLocation().X + TileToGridCenter;
	GridLocation.Y = (Column * TileSize) + AActor::GetActorLocation().Y + TileToGridCenter;
}


// Called every frame
void AGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


