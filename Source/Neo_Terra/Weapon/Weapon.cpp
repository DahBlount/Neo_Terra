// Fill out your copyright notice in the Description page of Project Settings.

#include "Neo_Terra.h"
#include "Weapon.h"
#include "Engine.h"

// Sets default values
AWeapon::AWeapon(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	WeaponMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Weapon Mesh"));
	RootComponent = WeaponMesh;

	TrailComp = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("Weapon Trail"));
	TArray<FName> MeshSockets = WeaponMesh->GetAllSocketNames();
	for (auto It = MeshSockets.CreateConstIterator(); It; ++It)
	{
		FName* Socket = MeshSockets.FindByKey(*It);
		FString SocketString = Socket->ToString();
		if ((SocketString.Contains(TEXT("Thruster"), ESearchCase::CaseSensitive, ESearchDir::FromStart)) || (SocketString.Contains(TEXT("Trail"), ESearchCase::CaseSensitive, ESearchDir::FromStart)))
		{
			TrailComp->AttachTo(RootComponent, *Socket);
		}
	}
}

void AWeapon::Fire()
{

}

void AWeapon::InstantFire()
{

}