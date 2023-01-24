// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "UnrealJordakaPlayerState.generated.h"

class UUnrealJordakaAbilitySystemComponent;
class UUnrealJordakaHealthAttributeSet;

UCLASS()
class AUnrealJordakaPlayerState : public APlayerState, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    AUnrealJordakaPlayerState();

    UUnrealJordakaAbilitySystemComponent* GetUnrealJordakaAbilitySystemComponent() const { return AbilitySystemComponent; }
    UAbilitySystemComponent* GetAbilitySystemComponent() const override;
    UUnrealJordakaHealthAttributeSet* GetHealthAttributeSet() const;

private:
    UPROPERTY()
    UUnrealJordakaAbilitySystemComponent* AbilitySystemComponent;

    UPROPERTY()
    UUnrealJordakaHealthAttributeSet* HealthAttributeSet;
    
};
