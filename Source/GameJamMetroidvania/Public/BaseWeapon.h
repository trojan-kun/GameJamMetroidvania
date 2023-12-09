
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class GAMEJAMMETROIDVANIA_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();
	virtual void Fire();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components");
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		APlayerController* PC;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components");
	FName Gun_socket = "WeaponSocket";

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
	float TraceMaxDistance = 15000000000.0f;

	virtual void BeginPlay() override;

	void MakeShot();
};
