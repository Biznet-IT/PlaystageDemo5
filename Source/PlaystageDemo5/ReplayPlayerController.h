// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ReplayPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PLAYSTAGEDEMO5_API AReplayPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	//UFUNCTION(BlueprintCallable, Category = "Replays")
	//void RestartRecording();

	AReplayPlayerController(const FObjectInitializer& ObjectInitializer);

	/* Set the Paused State of the Running Replay to bDoPause. Return new Pause State */
	UFUNCTION(BlueprintCallable, Category = "CurrentReplay")
	bool SetCurrentReplayPausedState(bool bDoPause);

	/* Gets the Max Number of Seconds that were recorded in the current Replay */
	UFUNCTION(BlueprintCallable, Category = "CurrentReplay")
	int32 GetCurrentReplayTotalTimeInSeconds() const;

	/* Gets the Second we are currently watching in the Replay */
	UFUNCTION(BlueprintCallable, Category = "CurrentReplay")
	int32 GetCurrentReplayCurrentTimeInSeconds() const;

	/* Jumps to the specified Second in the Replay we are watching */
	UFUNCTION(BlueprintCallable, Category = "CurrentReplay")
	void SetCurrentReplayTimeToSeconds(int32 Seconds);

	/* Changes the PlayRate of the Replay we are watching, enabling FastForward or SlowMotion */
	UFUNCTION(BlueprintCallable, Category = "CurrentReplay")
	void SetCurrentReplayPlayRate(float PlayRate = 1.f);

	//protected:
		/*   for saving Anti - Aliasing and Motion - Blur settings during Pause State */
		//int32 PreviousAASetting;
		//int32 PreviousMBSetting;
};
