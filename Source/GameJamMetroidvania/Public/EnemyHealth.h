// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyHealth.generated.h"

UCLASS()
class GAMEJAMMETROIDVANIA_API AEnemyHealth : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyHealth();

	float GetHealth() const { return Health; }

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxHealth = 100.0f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	float Health = 0.0f;
};
