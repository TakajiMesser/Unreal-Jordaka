// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJordakaHealthAttributeSet.h"
#include "Abilities/UnrealJordakaAbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffectTypes.h"

UUnrealJordakaHealthAttributeSet::UUnrealJordakaHealthAttributeSet()
    : Health(100.0f)
    , MaxHealth(100.0f)
{
}

void UUnrealJordakaHealthAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaHealthAttributeSet, Health, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UUnrealJordakaHealthAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UUnrealJordakaHealthAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

    if (Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
    }
}

void UUnrealJordakaHealthAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
    Super::PostAttributeChange(Attribute, OldValue, NewValue);

    if (Attribute == GetMaxHealthAttribute())
    {
        if (GetHealth() > NewValue)
        {
            UUnrealJordakaAbilitySystemComponent* AbilitySystem = GetAbilitySystemComponent();

            if (AbilitySystem)
            {
                AbilitySystem->ApplyModToAttribute(GetHealthAttribute(), EGameplayModOp::Override, NewValue);
            }
        }
    }
}

bool UUnrealJordakaHealthAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
    return Super::PreGameplayEffectExecute(Data);
}

void UUnrealJordakaHealthAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);
}

void UUnrealJordakaHealthAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaHealthAttributeSet, Health, OldValue);
}

void UUnrealJordakaHealthAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUnrealJordakaHealthAttributeSet, MaxHealth, OldValue);
}
