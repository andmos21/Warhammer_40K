// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class WARHAMMER_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void HandlePhase();

	void SetupMovePhase();

	void MovePhase();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//What Phase this unit is on
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Phase = 0;

	//How many hits this unit can take
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Wound = 2;

	//How far this unit can move
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MovementAllowance = 4;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool CanMove = false;

	//The tile the actor wishes to move to
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int GridGoalX = -1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int GridGoalY = -1;

	//The tile the actor currently stands in
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int GridX = -1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int GridY = -1;
};
