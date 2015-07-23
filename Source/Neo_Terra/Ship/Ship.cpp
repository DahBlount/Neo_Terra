// Fill out your copyright notice in the Description page of Project Settings.

#include "Neo_Terra.h"
#include "Ship.h"


// Sets default values
AShip::AShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShip::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

FRotator AShip::GetRotationToTarget(UStaticMeshComponent* Component, FVector TargetPosition, FName Socket)
{
	TArray<USceneComponent*> ParentComponents;

	Component->GetParentComponents(ParentComponents);

	USceneComponent* Parent = ParentComponents[0];

	auto ParentTransform = Parent->GetSocketTransform(Socket);

	FVector TargetPositionLocal = ParentTransform.InverseTransformPosition(TargetPosition);

	return FRotationMatrix::MakeFromX(TargetPositionLocal).Rotator();
}

void AShip::UpdateTurretRotation(AActor* Target, FTurret Turret, float DeltaTime, float BaseRotationSpeed,
	float PositiveBaseRotationConstraint, float NegativeBaseRotationConstraint,
	float BarrelRotationSpeed, float PositiveBarrelRotationConstraint,
	float NegativeBarrelRotationConstraint)
{
	FVector TargetLocation{ 0, 0, 0 };
	auto BodyTransform = Turret.Base->GetRelativeTransform();
	auto bdyRotation = BodyTransform.GetRotation().Rotator();

	if (Target == nullptr)
	{
		auto tgtRotation = FMath::RInterpTo(bdyRotation, FRotator::ZeroRotator, DeltaTime, BaseRotationSpeed);
		Turret.Base->SetRelativeRotation(tgtRotation);

		if (Turret.Barrel != nullptr)
		{
			auto BarrelTransform = Turret.Barrel->GetRelativeTransform();
			auto brlRotation = BarrelTransform.GetRotation().Rotator();
			tgtRotation = FMath::RInterpTo(brlRotation, FRotator::ZeroRotator, DeltaTime, BarrelRotationSpeed);
			Turret.Barrel->SetRelativeRotation(tgtRotation);
		}

		return;
	}

	TargetLocation = Target->GetTransform().GetLocation();

	MakeTurretFacePosition(TargetLocation, Turret, DeltaTime, BaseRotationSpeed, PositiveBaseRotationConstraint,
		NegativeBaseRotationConstraint, BarrelRotationSpeed, PositiveBarrelRotationConstraint,
		NegativeBarrelRotationConstraint);
}

void AShip::MakeTurretFacePosition(FVector TargetPosition, FTurret Turret, float DeltaTime, float BaseRotationSpeed,
	float PositiveBaseRotationConstraint, float NegativeBaseRotationConstraint,
	float BarrelRotationSpeed, float PositiveBarrelRotationConstraint,
	float NegativeBarrelRotationConstraint)
{
	auto BodyTransform = Turret.Base->GetRelativeTransform();
	auto bdyRotation = BodyTransform.GetRotation().Rotator();

	auto TargetRotation = GetRotationToTarget(Turret.Base, TargetPosition, Turret.TurretSocket);
	auto yawDegrees = FMath::ClampAngle(TargetRotation.Yaw, NegativeBaseRotationConstraint, PositiveBaseRotationConstraint);
	FRotator baseTargetRotation{ 0.0f, yawDegrees, 0.0f };
	baseTargetRotation = FMath::RInterpTo(bdyRotation, baseTargetRotation, DeltaTime, BaseRotationSpeed);
	Turret.Base->SetRelativeRotation(baseTargetRotation);

	if (Turret.Barrel != nullptr)
	{
		auto BarrelTransform = Turret.Barrel->GetRelativeTransform();
		auto brlRotation = BarrelTransform.GetRotation().Rotator();

		TargetRotation = GetRotationToTarget(Turret.Barrel, TargetPosition, Turret.BarrelSocket);
		float pitchDegrees = TargetRotation.Pitch;
		pitchDegrees = FMath::ClampAngle(pitchDegrees, NegativeBarrelRotationConstraint, PositiveBarrelRotationConstraint);
		FRotator barrelTargetRotation{ pitchDegrees, 0.0f, 0.0f };
		barrelTargetRotation = FMath::RInterpTo(brlRotation, barrelTargetRotation, DeltaTime, BarrelRotationSpeed);
		Turret.Barrel->SetRelativeRotation(barrelTargetRotation);
	}
}