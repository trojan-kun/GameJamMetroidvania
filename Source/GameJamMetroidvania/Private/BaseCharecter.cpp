// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharecter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ABaseCharecter::ABaseCharecter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharecter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharecter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharecter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharecter::MoveForward);
	PlayerInputComponent->BindAxis("MoveLeft", this, &ABaseCharecter::MoveLeft);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharecter::MoveRight);
}

void ABaseCharecter::MoveForward(float Amount) {}
void ABaseCharecter::MoveLeft(float Amount) {}
void ABaseCharecter::MoveRight(float Amount) {}


