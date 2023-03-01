// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UnrealJordakaAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "UnrealJordakaMoveAttributeSet.generated.h"

UCLASS()
class UUnrealJordakaMoveAttributeSet : public UUnrealJordakaAttributeSet
{
    GENERATED_BODY()

public:
    UUnrealJordakaMoveAttributeSet();

    ATTRIBUTE_ACCESSORS(UUnrealJordakaMoveAttributeSet, Speed);

protected:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
    virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    
    UFUNCTION()
    void OnRep_Speed(const FGameplayAttributeData& OldValue);

private:
    UPROPERTY(BlueprintReadOnly, Category = "Move", ReplicatedUsing = OnRep_Speed, Meta = (HideFromModifiers, AllowPrivateAccess = "true"))
    FGameplayAttributeData Speed;

};
