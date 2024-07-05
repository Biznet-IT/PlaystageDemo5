// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ReplayPlayerControllerB.h"
#include "Engine/World.h"

void AReplayPlayerControllerB::StartRecording()
{
    UWorld* World = GEngine->GameViewport->GetWorld();
    //AWorldSettings* WorldSettings = GetWorldSettings();
    APlayerController* PlayerController = World->GetFirstPlayerController();
    if (PlayerController)
    {
        PlayerController->ConsoleCommand("DemoRec MyReplay", true);
    }
}

void AReplayPlayerControllerB::StopRecording()
{
    UWorld* World = GEngine->GameViewport->GetWorld();
    APlayerController* PlayerController = World->GetFirstPlayerController();
    if (PlayerController)
    {
        PlayerController->ConsoleCommand("DemoStop", true);
    }
}

void AReplayPlayerControllerB::PlayReplay()
{
    UWorld* World = GEngine->GameViewport->GetWorld();
    APlayerController* PlayerController = World->GetFirstPlayerController();
    if (PlayerController)
    {
        PlayerController->ConsoleCommand("DemoPlay MyReplay", true);
    }
}
