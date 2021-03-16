// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WHProjectCharacter.generated.h"


UCLASS(Blueprintable)
class AWHProjectCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AWHProjectCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	//Phases: 0 - Setup, 1 - Movement, 2 - Movement Spent, 3 - Movement Pause for Attack, 4 - Enemy Scanning Phase, 5 - Attack, 10 - reset
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Phase = 0;

	//The maximum amount of distance the character can move
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxTravelDistance = 1000.f;

	//How Long the character has moved this turn
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TurnDistanceTravelled = 0.f;

	//The Location where the character started this turn.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector StartTurnLocation;

	//List of targets within range
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<ACharacter*> Enemies;

	//Range, the size modifier of the Trigger sphere in BP.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Range = 12.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int EnemyInFocus = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool SearchingForEnemy = false;

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;

	//Master Phase handling function
	void HandlePhase();

	//Movement handling function
	void MovePhase();

	//Attack handling function
	void AttackPhase();

	void LookAtTarget();


	FVector LastTickLocation;

	
	
	

	float DefaultMaxWalkSpeed;
};

