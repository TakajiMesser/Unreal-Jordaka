// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UnrealJordakaAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "UnrealJordakaMeleeAttributeSet.generated.h"

UCLASS()
class UUnrealJordakaMeleeAttributeSet : public UUnrealJordakaAttributeSet
{
    GENERATED_BODY()

public:
    UUnrealJordakaMeleeAttributeSet();

    ATTRIBUTE_ACCESSORS(UUnrealJordakaMeleeAttributeSet, Damage);
    ATTRIBUTE_ACCESSORS(UUnrealJordakaMeleeAttributeSet, Range);
    ATTRIBUTE_ACCESSORS(UUnrealJordakaMeleeAttributeSet, Speed);
    ATTRIBUTE_ACCESSORS(UUnrealJordakaMeleeAttributeSet, Accuracy);
    ATTRIBUTE_ACCESSORS(UUnrealJordakaMeleeAttributeSet, CritChance);

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

private:
    UPROPERTY(BlueprintReadOnly, Category = "Melee", ReplicatedUsing = OnRep_Damage, Meta = (HideFromModifiers, AllowPrivateAccess = "true"))
    FGameplayAttributeData Damage;

    UPROPERTY(BlueprintReadOnly, Category = "Melee", ReplicatedUsing = OnRep_Range, Meta = (HideFromModifiers, AllowPrivateAccess = "true"))
    FGameplayAttributeData Range;

    UPROPERTY(BlueprintReadOnly, Category = "Melee", ReplicatedUsing = OnRep_Speed, Meta = (HideFromModifiers, AllowPrivateAccess = "true"))
    FGameplayAttributeData Speed;

    UPROPERTY(BlueprintReadOnly, Category = "Melee", ReplicatedUsing = OnRep_Accuracy, Meta = (HideFromModifiers, AllowPrivateAccess = "true"))
    FGameplayAttributeData Accuracy;

    UPROPERTY(BlueprintReadOnly, Category = "Melee", ReplicatedUsing = OnRep_CritChance, Meta = (HideFromModifiers, AllowPrivateAccess = "true"))
    FGameplayAttributeData CritChance;

};
