// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "UnrealJordakaCameraComponent.generated.h"

UCLASS()
class UUnrealJordakaCameraComponent : public UCameraComponent
{
    GENERATED_BODY()

public:
    UUnrealJordakaCameraComponent();

protected:
    virtual void GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView) override;

};

