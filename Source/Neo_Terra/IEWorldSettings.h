// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/WorldSettings.h"
#include "Weapon/Weapon.h"
#include "Ship/Ship.h"
#include "IEWorldSettings.generated.h"

/**
 * 
 */
UCLASS()
class NEO_TERRA_API AIEWorldSettings : public AWorldSettings
{
	GENERATED_BODY()

	TArray<AWeapon> WeaponArray;
	TArray<FWeaponData> WeaponInfoArray;
	TArray<AShip> ShipArray;

};
