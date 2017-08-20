// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h" /** no header files after this one, should always be the last in the list */

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//** return the mesh for the pickup */
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

private:
	/** static mesh to represent the pickup in the level */
	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Pickup", meta = (AllowPrivateAccess = true))
	class UStaticMeshComponent* PickupMesh; // class forward declaration
	
};
