// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryPickup.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ABatteryPickup::ABatteryPickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// PrimaryActorTick.bCanEverTick = false;
	
	GetMesh()->SetSimulatePhysics(true);

	/** the base power level of the battery */
	BatteryPower = 150.f;

}

void ABatteryPickup::WasCollected_Implementation()
{
	/** use base pickup behavior */
	Super::WasCollected_Implementation();
	/** destroy the battery */
	Destroy();
}

/** report the power level of the battery */
float ABatteryPickup::GetPower()
{
	return BatteryPower;
}
