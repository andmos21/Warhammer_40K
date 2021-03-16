// Copyright Epic Games, Inc. All Rights Reserved.

#include "WHProjectGameMode.h"
#include "WHProjectPlayerController.h"
#include "WHProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWHProjectGameMode::AWHProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AWHProjectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}