// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJordakaRangedAttributeSet.h"
#include "Abilities/UnrealJordakaAbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffectTypes.h"

UUnrealJordakaRangedAttributeSet::UUnrealJordakaRangedAttributeSet()
    : Damage(100.0f)
    , Range(100.0f)
    , Speed(100.0f)
    , Accuracy(100.0f)
    , CritChance(100.0f)
    , ReloadSpeed(100.0f)
{
}

void UUnrealJordakaRangedAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaRangedAttributeSet, Damage, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaRangedAttributeSet, Range, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaRangedAttributeSet, Speed, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaRangedAttributeSet, Accuracy, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaRangedAttributeSet, CritChance, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaRangedAttributeSet, ReloadSpeed, COND_None, REPNOTIFY_Always);
}

void UUnrealJordakaRangedAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

    if (Attribute == GetDamageAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
    }
    else if (Attribute == GetRangeAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
    }
    else if (Attribute == GetSpeedAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
    }
    else if (Attribute == GetAccuracyAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
    }
    else if (Attribute == GetCritChanceAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
    }
    else if (Attribute == GetReloadSpeedAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
    }
}

void UUnrealJordakaRangedAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
    Super::PostAttributeChange(Attribute, OldValue, NewValue);
}

bool UUnrealJordakaRangedAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
    return Super::PreGameplayEffectExecute(Data);
}

void UUnrealJordakaRangedAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);
}

void UUnrealJordakaRangedAttributeSet::OnRep_Damage(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaRangedAttributeSet, Damage, OldValue);
}

void UUnrealJordakaRangedAttributeSet::OnRep_Range(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaRangedAttributeSet, Range, OldValue);
}

void UUnrealJordakaRangedAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaRangedAttributeSet, Speed, OldValue);
}

void UUnrealJordakaRangedAttributeSet::OnRep_Accuracy(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaRangedAttributeSet, Accuracy, OldValue);
}

void UUnrealJordakaRangedAttributeSet::OnRep_CritChance(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaRangedAttributeSet, CritChance, OldValue);
}

void UUnrealJordakaRangedAttributeSet::OnRep_ReloadSpeed(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaRangedAttributeSet, ReloadSpeed, OldValue);
}
