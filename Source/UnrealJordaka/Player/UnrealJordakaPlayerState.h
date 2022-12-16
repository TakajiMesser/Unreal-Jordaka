// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "UnrealJordakaPlayerState.generated.h"

class UUnrealJordakaAbilitySystemComponent;
class UUnrealJordakaAttributeSet;

UCLASS()
class AUnrealJordakaPlayerState : public APlayerState, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    AUnrealJordakaPlayerState();

    UUnrealJordakaAbilitySystemComponent* GetUnrealJordakaAbilitySystemComponent() const { return AbilitySystemComponent; }
    UAbilitySystemComponent* GetAbilitySystemComponent() const override;
    UUnrealJordakaAttributeSet* GetAttributeSet() const;

private:
	UPROPERTY()
	UUnrealJordakaAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	UUnrealJordakaAttributeSet* AttributeSet;
    
};
