// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UnrealJordakaQuality.h"
#include "UnrealJordakaWeaponDefinition.generated.h"

UENUM(BlueprintType)
enum class EUnrealJordakaWeaponType : uint8
{
    Melee = 0,
    Ranged
};

UCLASS(Blueprintable, BlueprintType, Const, Meta = (DisplayName = "Weapon Data", ShortTooltip = "Data asset used to configure a weapon."))
class UUnrealJordakaWeaponDefinition : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    FName ID;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    FText Name;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    FText Description;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    EUnrealJordakaWeaponType WeaponType;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    EUnrealJordakaQuality Quality;

};
