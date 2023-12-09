// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "Components/InputComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/PlayerController.h"

DEFINE_LOG_CATEGORY_STATIC(LogWeapon, All, All);

// Sets default values
ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);

	PC = CreateDefaultSubobject<APlayerController>("BP_PLayerController");
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

	check(WeaponMesh);
}

void ABaseWeapon::MakeShot()
{
	if (!GetWorld()) return;

	const FTransform SocketTransform = WeaponMesh->GetSocketTransform(Gun_socket);
	const FVector TraceStart = SocketTransform.GetLocation();
	float MouseX;
	float MouseY;
	
	PC->GetMousePosition(MouseX, MouseY);
	PC->bShowMouseCursor = false;

	UE_LOG(LogTemp, Warning, TEXT("The boolean value is %s"), (PC->GetMousePosition(MouseX, MouseY) ? TEXT("true") : TEXT("false")));
	UE_LOG(LogWeapon, Display, TEXT("Mouse X %s"), MouseX);
	UE_LOG(LogWeapon, Display, TEXT("Mouse Y %s"), MouseY);

	const FVector ShootDirection(MouseX, MouseY, TraceStart.Z);
	const FVector TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
	PC->bShowMouseCursor = true;
	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);

}


