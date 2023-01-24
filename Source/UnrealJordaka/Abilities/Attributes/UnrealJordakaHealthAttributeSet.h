// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UnrealJordakaAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "UnrealJordakaHealthAttributeSet.generated.h"

UCLASS()
class UUnrealJordakaHealthAttributeSet : public UUnrealJordakaAttributeSet
{
    GENERATED_BODY()

public:
    UUnrealJordakaHealthAttributeSet();

    ATTRIBUTE_ACCESSORS(UUnrealJordakaHealthAttributeSet, Health);
    ATTRIBUTE_ACCESSORS(UUnrealJordakaHealthAttributeSet, MaxHealth);

protected:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
    virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    
    UFUNCTION()
    void OnRep_Health(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

private:
    UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_Health, Meta = (HideFromModifiers, AllowPrivateAccess = "true"))
    FGameplayAttributeData Health;

    UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth, Meta = (AllowPrivateAccess = "true"))
    FGameplayAttributeData MaxHealth;

};
