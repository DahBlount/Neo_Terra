// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

USTRUCT()
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Data")
		FString WeaponName;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Data")
		uint8 WeaponType;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Data")
		uint32 MaxAmmo;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Data")
		float TimeBetweenShots;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Data")
		uint32 ShotCost;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Data")
		float WeaponRange;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Data")
		float WeaponSpread;
};

UCLASS()
class NEO_TERRA_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon(const FObjectInitializer& ObjectInitializer);

	// Object number of this weapon
	uint16 WeaponObjNum;

	// Config data related to the weapon, this contains all of the weapons information
	FWeaponData* WeaponConfig;

private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
};