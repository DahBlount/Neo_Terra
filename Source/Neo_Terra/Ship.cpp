// Fill out your copyright notice in the Description page of Project Settings.

#include "Neo_Terra.h"
#include "Ship.h"


// Sets default values
AShip::AShip()
	:Super()
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
 
// A ship wants to fire a weapon, let's find all of its data then call Weapon_Create
void AShip::FireWeapon()
{
}