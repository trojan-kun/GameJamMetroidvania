// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseWeapon.h"
#include "WeaponComp.generated.h"

class ABaseWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEJAMMETROIDVANIA_API UWeaponComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComp();

	void Fire();

protected:

	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSubclassOf<ABaseWeapon> WeaponClass;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		FName WeaponAttachP = "WeaponSocket";

public:	


private:
	UPROPERTY()
		ABaseWeapon* CurrentWeapon = nullptr;
	void SpawnWeapon();
};
