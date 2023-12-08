// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Sight.h"
#include "WeaponComp.h"

// Sets default values
ABasePlayer::ABasePlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SetupStimulusSource();

	Health = DefaultHealth;

	WeaponComponent = CreateDefaultSubobject<UWeaponComp>("WeaponComponent");
}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PC = Cast<APlayerController>(GetController());

	if (PC)
	{
		PC->bShowMouseCursor = true;
		PC->bEnableClickEvents = true;
		PC->bEnableMouseOverEvents = true;
	}


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
	check(WeaponComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABasePlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABasePlayer::MoveRight);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, WeaponComponent, &UWeaponComp::Fire);
	//PlayerInputComponent->BindVectorAxis("ShootTragectory", this, &UWeaponComp::Fire);
}

void ABasePlayer::MoveForward(float Amount) {
	AddMovementInput(GetActorForwardVector(), Amount);
}

void ABasePlayer::MoveRight(float Amount) {
	AddMovementInput(GetActorRightVector(), Amount);
}


void ABasePlayer::SetupStimulusSource()
{
	StimulusSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimulus"));
	if (StimulusSource)
	{
		StimulusSource->RegisterForSense(TSubclassOf<UAISense_Sight>());
		StimulusSource->RegisterWithPerceptionSystem();
	}
}

float ABasePlayer::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, 
	class AController* EventInstigator, AActor* DamageCauser) 
{
	Health -= DamageAmount;
	UE_LOG(LogTemp, Warning, TEXT("Health: % f"), Health);

	if (Health > 0) 
	{
		UE_LOG(LogTemp, Warning, TEXT("You DEAD!"));

		//ÏÅðåçàãðóçêà ïîñëå ñìåðòè èëè ÷òî òàì ó íàñ áóäåò
	}

	return DamageAmount;

}

