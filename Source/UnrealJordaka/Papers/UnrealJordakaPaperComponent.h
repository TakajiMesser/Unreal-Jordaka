// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PaperSprite.h"
#include "PaperFlipbook.h"
#include "PaperSpriteComponent.h"
#include "PaperFlipbookComponent.h"
#include "UnrealJordakaPaperComponent.generated.h"

UENUM(BlueprintType)
enum class EUnrealJordakaStance : uint8
{
    Idle,
    Walking,
    Rolling
};

UENUM(BlueprintType)
enum class EUnrealJordakaDirection : uint8
{
    Forwards,
    Backwards,
    Rightwards,
    Leftwards
};

UCLASS(Blueprintable)
class UUnrealJordakaPaperComponent : public USceneComponent
{
    GENERATED_BODY()

public:
    UUnrealJordakaPaperComponent();

    UPaperFlipbookComponent* GetFlipbook(EUnrealJordakaStance stance, EUnrealJordakaDirection direction);

private:
    UPaperFlipbookComponent* CreateFlipbook(const TCHAR* name, const TCHAR* assetPath);

    UPROPERTY(VisibleDefaultsOnly)
    UPaperFlipbookComponent* IdleFrontFlipbook;
};

