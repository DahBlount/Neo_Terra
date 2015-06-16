// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Neo_Terra.h"
#include "TP_TopDownGameMode.h"
#include "TP_TopDownPlayerController.h"
#include "TP_TopDownCharacter.h"

ATP_TopDownGameMode::ATP_TopDownGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// use our custom PlayerController class
	PlayerControllerClass = ATP_TopDownPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}