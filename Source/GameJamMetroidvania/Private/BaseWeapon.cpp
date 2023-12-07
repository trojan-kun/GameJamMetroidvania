// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"


DEFINE_LOG_CATEGORY_STATIC(LogWeapon, All, All);

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ABaseWeapon::Fire()
{
	UE_LOG(LogWeapon, Display, TEXT("Fire")); 
	MakeShot();
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseWeapon::MakeShot()
{
	if (GetWorld())return;

	const FTransform SocketTransform = WeaponMesh->GetSocketTransform(Gun_socket);
	const FVector TraceStart = SocketTransform.GetLocation();
	const FVector ShootDirection = SocketTransform.GetRotation().GetForwardVector();
	const FVector TraceEnd = TraceStart + ShootDirection * 1500.0f;

	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);

}


