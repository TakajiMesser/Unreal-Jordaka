// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJordakaPlayerAttributeSet.h"
#include "Abilities/UnrealJordakaAbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffectTypes.h"

UUnrealJordakaPlayerAttributeSet::UUnrealJordakaPlayerAttributeSet()
    : Speed(100.0f)
{
}

void UUnrealJordakaPlayerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaPlayerAttributeSet, Speed, COND_None, REPNOTIFY_Always);
}

void UUnrealJordakaPlayerAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

    if (Attribute == GetSpeedAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
    }
}

void UUnrealJordakaPlayerAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
    Super::PostAttributeChange(Attribute, OldValue, NewValue);
}

bool UUnrealJordakaPlayerAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
    return Super::PreGameplayEffectExecute(Data);
}

void UUnrealJordakaPlayerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);
}

void UUnrealJordakaPlayerAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaPlayerAttributeSet, Speed, OldValue);
}
