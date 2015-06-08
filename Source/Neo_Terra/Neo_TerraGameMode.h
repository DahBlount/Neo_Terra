// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core.h"
#include "Engine.h"
#include "GameFramework/GameMode.h"
#include "Neo_TerraGameMode.generated.h"

/**
 * 
 */

UCLASS()
class NEO_TERRA_API ANeo_TerraGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	ANeo_TerraGameMode(const FObjectInitializer& ObjectInitializer);	//Set default values

	virtual void StartPlay() override;	//override the default start play function

};
