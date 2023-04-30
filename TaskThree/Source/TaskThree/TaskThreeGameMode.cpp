// Copyright Epic Games, Inc. All Rights Reserved.

#include "TaskThreeGameMode.h"
#include "MyCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATaskThreeGameMode::ATaskThreeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
