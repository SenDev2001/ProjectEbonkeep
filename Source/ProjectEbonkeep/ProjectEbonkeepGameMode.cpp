// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectEbonkeepGameMode.h"
#include "ProjectEbonkeepCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectEbonkeepGameMode::AProjectEbonkeepGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
