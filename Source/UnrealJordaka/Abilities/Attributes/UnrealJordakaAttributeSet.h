// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "UnrealJordakaAttributeSet.generated.h"

class UUnrealJordakaAbilitySystemComponent;

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class UUnrealJordakaAttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
	UUnrealJordakaAttributeSet();

	UUnrealJordakaAbilitySystemComponent* GetAbilitySystemComponent() const;

};
