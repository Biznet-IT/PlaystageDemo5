// Fill out your copyright notice in the Description page of Project Settings.


#include "ReplayMenuWidget.h"
#include "ReplayPlayerControllerB.h"
#include "Engine/World.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

void UReplayMenuWidget::StartRecording()
{
    if (AReplayPlayerControllerB* PlayerController = Cast<AReplayPlayerControllerB>(GetWorld()->GetFirstPlayerController()))
    {
        PlayerController->StartRecording();
    }
}

void UReplayMenuWidget::StopRecording()
{
    if (AReplayPlayerControllerB* PlayerController = Cast<AReplayPlayerControllerB>(GetWorld()->GetFirstPlayerController()))
    {
        PlayerController->StopRecording();
    }
}

void UReplayMenuWidget::ShowReplayList()
{
    TArray<FString> ReplayList = GetReplayList();
    // Populate your ScrollBox or ListView with ReplayList
}

TArray<FString> UReplayMenuWidget::GetReplayList()
{
    TArray<FString> ReplayList;
    IFileManager& FileManager = IFileManager::Get();
    FString ReplayDirectory = FPaths::ProjectSavedDir() / TEXT("Demos");
    FileManager.FindFiles(ReplayList, *ReplayDirectory, TEXT("*.demo"));
    return ReplayList;
}

void UReplayMenuWidget::SearchReplay(const FString& SearchText)
{
    TArray<FString> ReplayList = GetReplayList();
    ReplayList.RemoveAll([&SearchText](const FString& Replay) {
        return !Replay.Contains(SearchText);
        });
    // Populate your ScrollBox or ListView with filtered ReplayList
}

void UReplayMenuWidget::RenameReplay(const FString& OldName, const FString& NewName)
{
    FString ReplayDirectory = FPaths::ProjectSavedDir() / TEXT("Demos");
    FString OldPath = ReplayDirectory / OldName;
    FString NewPath = ReplayDirectory / NewName;
    IFileManager::Get().Move(*NewPath, *OldPath);
}

void UReplayMenuWidget::DeleteReplay(const FString& ReplayName)
{
    FString ReplayDirectory = FPaths::ProjectSavedDir() / TEXT("Demos");
    FString ReplayPath = ReplayDirectory / ReplayName;
    IFileManager::Get().Delete(*ReplayPath);
}
