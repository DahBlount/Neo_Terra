// Fill out your copyright notice in the Description page of Project Settings.

#include "Neo_Terra.h"
#include "NTCharacter.h"


// Sets default values
ANTCharacter::ANTCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANTCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("We are using NTCharacter!"));
	}
}

// Called every frame
void ANTCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ANTCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &ANTCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ANTCharacter::MoveRight);
	InputComponent->BindAxis("Turn", this, &ANTCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &ANTCharacter::AddControllerPitchInput);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ANTCharacter::OnStartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &ANTCharacter::OnStopJump);
}

void ANTCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		FRotator Rotation = Controller->GetControlRotation();

		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}

		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ANTCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void ANTCharacter::OnStartJump()
{
	bPressedJump = true;
}
void ANTCharacter::OnStopJump()
{
	bPressedJump = false;
}