// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UnrealJordakaQuality.h"
#include "UnrealJordakaItemDefinition.generated.h"

UCLASS(Blueprintable, BlueprintType, Const, Meta = (DisplayName = "Item Data", ShortTooltip = "Data asset used to configure an item."))
class UUnrealJordakaItemDefinition : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
    FName ID;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
    FText Name;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
    FText Description;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
    EUnrealJordakaQuality Quality;

};
