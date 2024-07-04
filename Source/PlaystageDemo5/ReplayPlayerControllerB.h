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
	
};

//Function to start recording a replay
void AReplayPlayerControllerB::StartRecording()
{
    AReplayPlayerControllerB* PlayerControllerB = GetWorld()->GetFirstPlayerController();
    if (PlayerControllerB)
    {
        PlayerControllerB->ConsoleCommand("DemoRec MyReplay", true);
    }
}

//Fuction to stop recording a replay
void AReplayPlayerControllerB::StopRecording()
{
    AReplayPlayerControllerB* PlayerControllerB = GetWorld()->GetFirstPlayerController();
    if (PlayerControllerB)
    {
        PlayerControllerB->ConsoleCommand("DemoStop", true);
    }
}

//Function to play a replay
void AReplayPlayerControllerB::PlayReplay()
{
    AReplayPlayerControllerB* PlayerControllerB = GetWorld()->GetFirstPlayerController();
    if (PlayerControllerB)
    {
        PlayerControllerB->ConsoleCommand("DemoPlay MyReplay", true);
    }
}
