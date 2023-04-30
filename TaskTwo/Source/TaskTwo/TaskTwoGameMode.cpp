// Copyright Epic Games, Inc. All Rights Reserved.

#include "TaskTwoGameMode.h"
#include "TaskTwoCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATaskTwoGameMode::ATaskTwoGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
