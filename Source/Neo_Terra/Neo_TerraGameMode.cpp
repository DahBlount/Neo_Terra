// Fill out your copyright notice in the Description page of Project Settings.

#include "Neo_Terra.h"
#include "Neo_TerraGameMode.h"


ANeo_TerraGameMode::ANeo_TerraGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void ANeo_TerraGameMode::StartPlay()
{
	Super::StartPlay();

	StartMatch();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HELLOW WORLD!"));
	}
}