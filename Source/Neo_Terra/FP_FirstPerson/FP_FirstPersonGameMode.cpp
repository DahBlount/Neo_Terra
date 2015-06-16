// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Neo_Terra.h"
#include "FP_FirstPersonGameMode.h"
#include "FP_FirstPersonHUD.h"
#include "FP_FirstPersonCharacter.h"

AFP_FirstPersonGameMode::AFP_FirstPersonGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFP_FirstPersonHUD::StaticClass();
}
