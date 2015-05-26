// Fill out your copyright notice in the Description page of Project Settings.

#include "Neo_Terra.h"
#include "FileRead.h"

TMap<FName, RECIPE> RecipeMap;

// Load our Config files
void LoadConfiguration()
{
	TCHAR CurrentDir[MAX_PATH];
	GetCurrentDirectory(sizeof(CurrentDir), CurrentDir);
	FString BaseCFG = FString(CurrentDir) + "\\config\\base.cfg";
	FString ItemCFG = FString(CurrentDir) + "\\config\\base_recipe_items.cfg";
	FString ModuleCFG = FString(CurrentDir) + "\\config\\base_recipe_modules.cfg";
	FString ArchetypeCFG = FString(CurrentDir) + "\\config\\base_archetypes.cfg";
}

FileRead::FileRead()
{
}

FileRead::~FileRead()
{
}