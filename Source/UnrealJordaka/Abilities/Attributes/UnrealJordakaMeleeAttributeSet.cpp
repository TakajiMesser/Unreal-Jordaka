// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJordakaMeleeAttributeSet.h"
#include "Abilities/UnrealJordakaAbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffectTypes.h"

UUnrealJordakaMeleeAttributeSet::UUnrealJordakaMeleeAttributeSet()
    : Damage(100.0f)
    , Range(100.0f)
    , Speed(100.0f)
    , Accuracy(100.0f)
    , CritChance(100.0f)
{
}

void UUnrealJordakaMeleeAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaMeleeAttributeSet, Damage, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaMeleeAttributeSet, Range, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaMeleeAttributeSet, Speed, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaMeleeAttributeSet, Accuracy, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaMeleeAttributeSet, CritChance, COND_None, REPNOTIFY_Always);
}

void UUnrealJordakaMeleeAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
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
}

void UUnrealJordakaMeleeAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
    Super::PostAttributeChange(Attribute, OldValue, NewValue);
}

bool UUnrealJordakaMeleeAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
    return Super::PreGameplayEffectExecute(Data);
}

void UUnrealJordakaMeleeAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);
}

void UUnrealJordakaMeleeAttributeSet::OnRep_Damage(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaMeleeAttributeSet, Damage, OldValue);
}

void UUnrealJordakaMeleeAttributeSet::OnRep_Range(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaMeleeAttributeSet, Range, OldValue);
}

void UUnrealJordakaMeleeAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaMeleeAttributeSet, Speed, OldValue);
}

void UUnrealJordakaMeleeAttributeSet::OnRep_Accuracy(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaMeleeAttributeSet, Accuracy, OldValue);
}

void UUnrealJordakaMeleeAttributeSet::OnRep_CritChance(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaMeleeAttributeSet, CritChance, OldValue);
}
