// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ABasePlayer::ABasePlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABasePlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABasePlayer::MoveRight);
}

void ABasePlayer::MoveForward(float Amount) {
	AddMovementInput(GetActorForwardVector(), Amount);
}

void ABasePlayer::MoveRight(float Amount) {
	AddMovementInput(GetActorRightVector(), Amount);
}
