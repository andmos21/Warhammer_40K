// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

UCLASS()
class WARHAMMER_API AGrid : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, BlueprintPure)
		float GridHeight() const;
	UFUNCTION(BlueprintCallable, BlueprintPure)
		float GridWidth() const;

	UFUNCTION(BlueprintCallable)
		bool TileValid(int Row, int Column);
	UFUNCTION(BlueprintCallable)
		void LocationToTile(FVector Loctation, bool& Valid, int32& Row, int32& Column);
	UFUNCTION(BlueprintCallable)
		void TileToGridLocation(int32 Row, int32 Column, bool Center, bool& Valid, FVector2D& GridLocation);

	//UFUNCTION(BlueprintCallable)
	//	void CreateLine(FVector Start, FVector End, float Thickness, const TArray<FVector> Vertices, TArray<int32> Triangles);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 NumRows = 10;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 NumColumns = 10;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float TileSize = 200.0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float LineThickness = 10.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLinearColor LineColor = { 0.051, 0.453, 0.033, 0.0 };
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLinearColor SelectionColor = { 0.167, 0.227, 1.0, 0.0 };

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float LineOpacity = 1.0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float SelectionOpacity = 0.25;
};