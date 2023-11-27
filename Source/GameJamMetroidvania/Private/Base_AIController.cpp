// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_AIController.h"
#include "EnemyBase.h"

ABase_AIController::ABase_AIController(FObjectInitializer const& ObjectInitializer) 
{

}

void ABase_AIController::OnPossess(APawn* InPawn) 
{
	Super::OnPossess(InPawn);
	if (AEnemyBase* const enemyBase = Cast<AEnemyBase>(InPawn))
	{
		if (UBehaviorTree* const tree = enemyBase->GetBehaviorTree())
		{
			UBlackboardComponent* b;
			UseBlackboard(tree->BlackboardAsset, b);
			Blackboard = b;
			RunBehaviorTree(tree);
		}
	}
}