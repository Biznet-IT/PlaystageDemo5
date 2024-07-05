// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ReplayPlayerControllerB.h"
#include "Engine/World.h"
#include "Misc/DateTime.h"

FString AReplayPlayerControllerB::GetTimestamp() const
{
    FDateTime Now = FDateTime::Now();
    return Now.ToString(TEXT("%Y%m%d%H%M%S"));
}

void AReplayPlayerControllerB::StartRecording()
{
    UWorld* World = GEngine->GameViewport->GetWorld();
    APlayerController* PlayerController = World->GetFirstPlayerController();
    if (PlayerController)
    {
        FString ReplayName = FString::Printf(TEXT("Replay_%s"), *GetTimestamp());
        PlayerController->ConsoleCommand(FString::Printf(TEXT("DemoRec %s"), *ReplayName), true);
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

void AReplayPlayerControllerB::PlayReplay(const FString& ReplayName)
{
    UWorld* World = GEngine->GameViewport->GetWorld();
    APlayerController* PlayerController = World->GetFirstPlayerController();
    if (PlayerController)
    {
        PlayerController->ConsoleCommand(FString::Printf(TEXT("DemoPlay %s"), *ReplayName), true);
    }
}
