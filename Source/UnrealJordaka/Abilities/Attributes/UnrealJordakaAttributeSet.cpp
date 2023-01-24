// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJordakaAttributeSet.h"
#include "Abilities/UnrealJordakaAbilitySystemComponent.h"

UUnrealJordakaAttributeSet::UUnrealJordakaAttributeSet()
{
}

UUnrealJordakaAbilitySystemComponent* UUnrealJordakaAttributeSet::GetAbilitySystemComponent() const
{
    return Cast<UUnrealJordakaAbilitySystemComponent>(GetOwningAbilitySystemComponent());
}
