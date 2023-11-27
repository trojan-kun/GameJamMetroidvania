// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Base_AIController.generated.h"

/**
 *
 */
UCLASS()
class GAMEJAMMETROIDVANIA_API ABase_AIController : public AAIController
{
	GENERATED_BODY()

public:
	explicit ABase_AIController(FObjectInitializer const& ObjectInitializer);

protected:
	virtual void OnPossess(APawn* InPawn) override;
};
