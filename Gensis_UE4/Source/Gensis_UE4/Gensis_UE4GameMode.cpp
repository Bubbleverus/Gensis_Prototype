// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Gensis_UE4.h"
#include "Gensis_UE4GameMode.h"
#include "Gensis_UE4Character.h"

AGensis_UE4GameMode::AGensis_UE4GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
