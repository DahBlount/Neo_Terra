// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UENUM()
namespace EWeaponProjectile
{
	enum ProjectileType
	{
		EBullet			UMETA(DislpayName = "Bullet"),
		ESpread			UMETA(DisplayName = "Spread"),
		EProjectile		UMETA(DisplayName = "Prjoectile")
	};
}

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
};

UCLASS()
class NEO_TERRA_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AWeapon(const FObjectInitializer& ObjectInitializer);

	// Fire a weapon
	UFUNCTION()
	void Fire();

	UFUNCTION()
	void InstantFire();

	// Config data related to the weapon, this contains all of the weapons information
	UPROPERTY(EditAnywhere, Category = "Config")
	FWeaponData WeaponConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	TEnumAsByte<EWeaponProjectile::ProjectileType> ProjectileType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	UBoxComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config")
	UParticleSystemComponent* TrailComp;
};

#define TYPE_NONE			0
#define TYPE_PROJECTILE		1
#define TYPE_MISSILE		2
#define TYPE_BEAM			3