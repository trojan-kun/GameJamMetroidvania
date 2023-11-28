// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ABasePlayer::ABasePlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = DefaultHealth;

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

float ABasePlayer::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, 
	class AController* EventInstigator, AActor* DamageCauser) 
{
	Health -= DamageAmount;
	UE_LOG(LogTemp, Warning, TEXT("Health: % f"), Health);

	if (Health > 0) {
		UE_LOG(LogTemp, Warning, TEXT("You DEAD!"));

		//ѕ≈резагрузка после смерти или что там у нас будет
	}

	return DamageAmount;
}

