// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ZombieEnemy.generated.h"

UCLASS()
class WHPROJECT_API AZombieEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombieEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool Active = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Phase = 0;

	float MA = 400.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Range = 50.f;

	int toHit = 2;

	int toSave = 4;

	float TurnDistanceTravelled = 0.f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ACharacter* Target = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Toughness = 1;

private:

	void HandlePhase();

	void MovePhase();

	FVector LastTickLocation;

};
