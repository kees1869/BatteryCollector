// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryCollectorGameMode.generated.h"


/** enum to store the current state of gameplay */
UENUM(BlueprintType)
enum class EBatteryPlayState : uint8
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** return power needed to win - needed for the HUD */
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetPowerToWin() const;

	virtual void BeginPlay() override;

	/** returns the current playing state */
	UFUNCTION(BLueprintPure, Category= "Power")

	/** sets a new playing state */
	EBatteryPlayState GetCurrentState() const;
	void SetCurrentState(EBatteryPlayState NewState);

protected:
	/** the rate at which the character loses power */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = true))
	float DecayRate;

	/** the power needed to win the game */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = true))
	float PowerToWin;

	/** the widget class to use for our HUD screen */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = true))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	/** the instance of the HUD */
	UPROPERTY()
	class UUserWidget* CurrentWidget;

private:
	/** keeps track of the current playing state */
	EBatteryPlayState CurrentState;
};
