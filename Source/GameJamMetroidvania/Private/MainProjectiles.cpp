// Fill out your copyright notice in the Description page of Project Settings.


#include "MainProjectiles.h"
#include "EnemyBase.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AMainProjectiles::AMainProjectiles()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	CollisionSphere->InitSphereRadius(20.0f);

	RootComponent = CollisionSphere;	

	BulletMovement = CreateDefaultSubobject < UProjectileMovementComponent>(TEXT("Bullet Movement"));
	BulletMovement->UpdatedComponent = CollisionSphere;
	BulletMovement -> InitialSpeed = 3000.0f;
	BulletMovement-> MaxSpeed = 3000.0f;
	BulletMovement->bRotationFollowsVelocity = true;
	BulletMovement->bShouldBounce = true;

	InitialLifeSpan = 5.0f;
}

// Called when the game starts or when spawned
void AMainProjectiles::BeginPlay()
{
	Super::BeginPlay();

	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AMainProjectiles::OHit);

}

// Called every frame
void AMainProjectiles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainProjectiles::OHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyI, bool bFromSweep, const FHitResult& OnHit)
{

}

