// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Weapon/Weapon.h"
#include "Ship.generated.h"

USTRUCT(BlueprintType)
struct FTurret
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Turret")
	UStaticMeshComponent* Base;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Turret")
	UStaticMeshComponent* Barrel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Turret")
	FName TurretSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Turret")
	FName BarrelSocket;
};

UCLASS()
class NEO_TERRA_API AShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShip();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void AShip::SetupPlayerInputComponent(class UInputComponent* InputComponent);

	void Roll(float Val);

	void MoveForward(float Val);

	void Strafe(float Val);

	/**
	* Given a component, a target location and the socket the component is attached to, get a rotator describing
	* the rotation necessary to make the component point at the target.
	* @param Component The StaticMeshComponent to be use as a base
	* @param TargetPosition The location that is targeted
	* @param Socket The socket the component is attached to.
	*/
	UFUNCTION(BlueprintCallable, Category = "Ship Weapon")
	FRotator GetRotationToTarget(UStaticMeshComponent* Component, FVector TargetPosition, FName Socket);

	/**
	* Given a Turret, rotate it and its barrels to face the target actor
	* @param Target The Target actor
	* @param Turret The Turret to rotate
	* @param DeltaTime Frametime delta as reported by the Tick event
	* @param BaseRotationSpeed How fast the turret base can rotate
	* @param PositiveBaseRotationConstraint The maximum angle a turret can rotate to
	* @param NegativeBaseRotationConstraint The minimum angle a turret can rotate to
	* @param BarrelRotationSpeed How fast the barrels can rotate
	* @param PositiveBarrelRotationConstraint The maximum elevation angle of the barrels
	* @param NegativeBarrelRotationConstraint The minimum elevation angle of the barrels
	*/
	UFUNCTION(BlueprintCallable, Category = "Ship Weapon")
	void UpdateTurretRotation(AActor* Target, FTurret Turret, float DeltaTime, float BaseRotationSpeed,
		float PositiveBaseRotationConstraint, float NegativeBaseRotationConstraint,
		float BarrelRotationSpeed, float PositiveBarrelRotationConstraint,
		float NegativeBarrelRotationConstraint);

	/**
	* Given a Turret, rotate it and its barrels to face the target location
	* @param TargetPosition The Target position
	* @param Turret The Turret to rotate
	* @param DeltaTime Frametime delta as reported by the Tick event
	* @param BaseRotationSpeed How fast the turret base can rotate
	* @param PositiveBaseRotationConstraint The maximum angle a turret can rotate to
	* @param NegativeBaseRotationConstraint The minimum angle a turret can rotate to
	* @param BarrelRotationSpeed How fast the barrels can rotate
	* @param PositiveBarrelRotationConstraint The maximum elevation angle of the barrels
	* @param NegativeBarrelRotationConstraint The minimum elevation angle of the barrels
	*/
	UFUNCTION(BlueprintCallable, Category = "Ship Weapon")
	void MakeTurretFacePosition(FVector TargetPosition, FTurret Turret, float DeltaTime, float BaseRotationSpeed,
		float PositiveBaseRotationConstraint, float NegativeBaseRotationConstraint,
		float BarrelRotationSpeed, float PositiveBarrelRotationConstraint,
		float NegativeBarrelRotationConstraint);
};
