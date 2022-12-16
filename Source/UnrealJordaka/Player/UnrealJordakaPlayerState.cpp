// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJordakaPlayerState.h"
#include "Abilities/UnrealJordakaAbilitySystemComponent.h"
#include "Abilities/Attributes/UnrealJordakaAttributeSet.h"
#include "UnrealJordakaPlayerController.h"

AUnrealJordakaPlayerState::AUnrealJordakaPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UUnrealJordakaAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UUnrealJordakaAttributeSet>(TEXT("AttributeSet"));
	
	NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* AUnrealJordakaPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UUnrealJordakaAttributeSet* AUnrealJordakaPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
