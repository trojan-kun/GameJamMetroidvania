// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Character.h"
#include "BaseWeapon.h"
#include "WeaponComp.h"

// Sets default values for this component's properties
UWeaponComp::UWeaponComp()
{

	PrimaryComponentTick.bCanEverTick = false;

}

void UWeaponComp::BeginPlay()
{
	Super::BeginPlay();

	SpawnWeapon();
}

void UWeaponComp::SpawnWeapon() {
	if (!GetWorld())return;

	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character) return;

	CurrentWeapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponClass);
	if (!CurrentWeapon) return;

	FAttachmentTransformRules AttachemntRules(EAttachmentRule::SnapToTarget, false);
	CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachemntRules, WeaponAttachP);

}

void UWeaponComp::Fire()
{
	if (!CurrentWeapon) return;
	CurrentWeapon->Fire();
}


