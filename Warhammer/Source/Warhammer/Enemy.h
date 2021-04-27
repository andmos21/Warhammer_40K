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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Phase = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MovementAllowance = 4;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int MovementUsed = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool CanMove = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int GridGoalX = -1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int GridGoalY = -1;


};
