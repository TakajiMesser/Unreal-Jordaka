// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UnrealJordakaCharacter.generated.h"

class UUnrealJordakaCameraComponent;

UCLASS(Blueprintable)
class AUnrealJordakaCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AUnrealJordakaCharacter();

    // Called every frame.
    virtual void Tick(float DeltaSeconds) override;

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", Meta = (AllowPrivateAccess = "true"))
    class UUnrealJordakaCameraComponent* CameraComponent;
};

