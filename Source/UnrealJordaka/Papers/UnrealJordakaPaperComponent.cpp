// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJordakaPaperComponent.h"
#include "UObject/ConstructorHelpers.h"

UUnrealJordakaPaperComponent::UUnrealJordakaPaperComponent()
{
    
}

UPaperFlipbookComponent* UUnrealJordakaPaperComponent::GetFlipbook(EUnrealJordakaStance stance, EUnrealJordakaDirection direction)
{
    return nullptr;
}

UPaperFlipbookComponent* UUnrealJordakaPaperComponent::CreateFlipbook(const TCHAR* name, const TCHAR* assetPath)
{
    UPaperFlipbookComponent* flipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(name);
    UPaperFlipbook* asset = ConstructorHelpers::FObjectFinder<UPaperFlipbook>(assetPath).Object;

    flipbook->SetFlipbook(asset);
    flipbook->SetupAttachment(this);
    flipbook->SetLooping(true);
    flipbook->SetRelativeLocation(FVector(0.0f, 0.0f, 10.0f));
    //flipbook->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
    flipbook->SetRelativeScale3D(FVector(4.0f));
    flipbook->SetWorldRotation(FRotator(0.0f, 0.0f, 0.0f));

    return flipbook;
}
