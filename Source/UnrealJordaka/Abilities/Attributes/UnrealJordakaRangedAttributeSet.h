// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UnrealJordakaAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "UnrealJordakaRangedAttributeSet.generated.h"

UCLASS()
class UUnrealJordakaRangedAttributeSet : public UUnrealJordakaAttributeSet
{
    GENERATED_BODY()

public:
    UUnrealJordakaRangedAttributeSet();

    ATTRIBUTE_ACCESSORS(UUnrealJordakaRangedAttributeSet, Damage);
    ATTRIBUTE_ACCESSORS(UUnrealJordakaRangedAttributeSet, Range);
    ATTRIBUTE_ACCESSORS(UUnrealJordakaRangedAttributeSet, Speed);
    ATTRIBUTE_ACCESSORS(UUnrealJordakaRangedAttributeSet, Accuracy);
    ATTRIBUTE_ACCESSORS(UUnrealJordakaRangedAttributeSet, CritChance);
    ATTRIBUTE_ACCESSORS(UUnrealJordakaRangedAttributeSet, ReloadSpeed);

protected:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
    virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    
    UFUNCTION()
    void OnRep_Damage(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    void OnRep_Range(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    void OnRep_Speed(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    void OnRep_Accuracy(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    void OnRep_CritChance(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    void OnRep_ReloadSpeed(const FGameplayAttributeData& OldValue);

private:
    UPROPERTY(BlueprintReadOnly, Category = "Ranged", ReplicatedUsing = OnRep_Damage, Meta = (HideFromModifiers, AllowPrivateAccess = "true"))
    FGameplayAttributeData Damage;

    UPROPERTY(BlueprintReadOnly, Category = "Ranged", ReplicatedUsing = OnRep_Range, Meta = (HideFromModifiers, AllowPrivateAccess = "true"))
    FGameplayAttributeData Range;

    UPROPERTY(BlueprintReadOnly, Category = "Ranged", ReplicatedUsing = OnRep_Speed, Meta = (HideFromModifiers, AllowPrivateAccess = "true"))
    FGameplayAttributeData Speed;

    UPROPERTY(BlueprintReadOnly, Category = "Ranged", ReplicatedUsing = OnRep_Accuracy, Meta = (HideFromModifiers, AllowPrivateAccess = "true"))
    FGameplayAttributeData Accuracy;

    UPROPERTY(BlueprintReadOnly, Category = "Ranged", ReplicatedUsing = OnRep_CritChance, Meta = (HideFromModifiers, AllowPrivateAccess = "true"))
    FGameplayAttributeData CritChance;

    UPROPERTY(BlueprintReadOnly, Category = "Ranged", ReplicatedUsing = OnRep_ReloadSpeed, Meta = (HideFromModifiers, AllowPrivateAccess = "true"))
    FGameplayAttributeData ReloadSpeed;

};
