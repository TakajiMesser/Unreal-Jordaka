// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJordakaMoveAttributeSet.h"
#include "Abilities/UnrealJordakaAbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffectTypes.h"

UUnrealJordakaMoveAttributeSet::UUnrealJordakaMoveAttributeSet()
    : Speed(100.0f)
{
}

void UUnrealJordakaMoveAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaMoveAttributeSet, Speed, COND_None, REPNOTIFY_Always);
}

void UUnrealJordakaMoveAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

    if (Attribute == GetSpeedAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
    }
}

void UUnrealJordakaMoveAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
    Super::PostAttributeChange(Attribute, OldValue, NewValue);
}

bool UUnrealJordakaMoveAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
    return Super::PreGameplayEffectExecute(Data);
}

void UUnrealJordakaMoveAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);
}

void UUnrealJordakaMoveAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaMoveAttributeSet, Speed, OldValue);
}
