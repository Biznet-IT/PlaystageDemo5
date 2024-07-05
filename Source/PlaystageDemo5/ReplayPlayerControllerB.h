// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ReplayPlayerControllerB.generated.h"

/**
 * 
 */
UCLASS()
class PLAYSTAGEDEMO5_API AReplayPlayerControllerB : public APlayerController
{
	GENERATED_BODY()

public:
    //function to start recording a replay
    UFUNCTION(BlueprintCallable, Category = "Replays")
    void StartRecording();

    //function to stop recording a replay
    UFUNCTION(BlueprintCallable, Category = "Replays")
    void StopRecording();

    //function to play a replay
    UFUNCTION(BlueprintCallable, Category = "Replays")
    void PlayReplay(const FString& ReplayName);

private:
    FString GetTimestamp() const;
};
