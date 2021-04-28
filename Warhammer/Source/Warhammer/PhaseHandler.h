// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhaseHandler.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARHAMMER_API UPhaseHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPhaseHandler();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Phase = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MovementAllowance = 6;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int MovementUsed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CurrentPhaseName = "MovePhase";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ManualPhaseAdvance = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanMove = false;

	//Main Function that decides which phase the game is in
	void HandlePhases();

	//Code that executes on start
	void InitializePhase();

	//Code that is called to start the movement phase
	void ToMovePhase();

	//Code that is called each frame during MovePhase
	void MovePhase();

	//Code that is called to start the attacking phase
	void ToAttackPhase();

	//Code that is called each frame during the AttackPhase
	void AttackPhase();

};
