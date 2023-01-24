// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJordakaPlayerState.h"
#include "Abilities/UnrealJordakaAbilitySystemComponent.h"
#include "Abilities/Attributes/UnrealJordakaHealthAttributeSet.h"
#include "UnrealJordakaPlayerController.h"

AUnrealJordakaPlayerState::AUnrealJordakaPlayerState()
{
    AbilitySystemComponent = CreateDefaultSubobject<UUnrealJordakaAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

    HealthAttributeSet = CreateDefaultSubobject<UUnrealJordakaHealthAttributeSet>(TEXT("HealthAttributeSet"));
    
    NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* AUnrealJordakaPlayerState::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

UUnrealJordakaHealthAttributeSet* AUnrealJordakaPlayerState::GetHealthAttributeSet() const
{
    return HealthAttributeSet;
}
