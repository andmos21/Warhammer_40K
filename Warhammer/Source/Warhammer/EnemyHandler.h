// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid.h"
#include "EnemyHandler.generated.h"

UCLASS()
class WARHAMMER_API AEnemyHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyHandler();

	void SpawnEnemies(int amount);

	void SpawnEnemy(int GridXLocation, int GridYLocation);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AGrid* LevelGrid = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
