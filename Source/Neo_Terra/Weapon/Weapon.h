// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ParticleDefinitions.h"
#include "Weapon.generated.h"

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
	FString WeaponName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
	uint8 WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
	int32 MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
	float TimeBetweenShots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
	int32 ShotCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
	float WeaponRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
	float WeaponSpread;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
	int32 WeaponFlags;
};

UCLASS()
class NEO_TERRA_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AWeapon(const FObjectInitializer& ObjectInitializer);

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
	void Rotate();

	// Fire a weapon
	UFUNCTION()
	void Fire();

	UFUNCTION()
	void InstantFire();

	// This is only used when the weapon is a Projectile or Beam
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trail")
	UParticleSystemComponent* TrailComponent;
};

#define TYPE_NONE			0
#define TYPE_PROJECTILE		1
#define TYPE_MISSILE		2
#define TYPE_BEAM			3

// Parse weapons
void ParseWeapon(uint8 Type, const FString Filename);
void ParseWeaponsIni(const FString Filename);
void InitWeapons();