// Fill out your copyright notice in the Description page of Project Settings.

#include "Neo_Terra.h"
#include "Weapon.h"
#include "Engine.h"
#include "ConfigCacheIni.h"

/* Parse a weapon
@param Type = The weapons type, can be a value from 1-3
@param Filename = The name of the weapons config file*/
void ParseWeapon(uint8 Type, const FString Filename)
{

}

/* Parse the weapons config file
@param Filename = The name of the weapons config file.*/
void ParseWeaponsIni(const FString Filename)
{

}

// Initialize weapons
void InitWeapons()
{

}

// Sets default values
AWeapon::AWeapon(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	WeaponMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Weapon Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/NeoTerra/Meshes/Shrike.Shrike'"));
	WeaponMesh->SetStaticMesh(MeshAsset.Object);
	RootComponent = WeaponMesh;

	TrailComponent = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("Weapon Trail"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/NeoTerra/Particles/P_MissileThruster.P_MissileThruster'"));
	TrailComponent->Template = ParticleAsset.Object;
	TArray<FName> MeshSockets = WeaponMesh->GetAllSocketNames();
	for (auto It = MeshSockets.CreateConstIterator(); It; ++It)
	{
		FName* Socket = MeshSockets.FindByKey(*It);
		FString SocketString = Socket->ToString();
		if ((SocketString.Contains(TEXT("Thruster"), ESearchCase::CaseSensitive, ESearchDir::FromStart)) || (SocketString.Contains(TEXT("Trail"), ESearchCase::CaseSensitive, ESearchDir::FromStart)))
		{
			TrailComponent->AttachTo(RootComponent, *Socket);
		}
	}
}

void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->Rotate();
}

void AWeapon::Rotate()
{
	const FRotator Rot = this->GetActorRotation();
	FVector Torque = Rot.RotateVector(FVector(15000000, 0, 0));
	this->WeaponMesh->AddTorque(Torque);
}

void AWeapon::Fire()
{

}

void AWeapon::InstantFire()
{

}