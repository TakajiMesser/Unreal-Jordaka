// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJordakaCameraComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/UnrealJordakaPlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"

UUnrealJordakaCameraComponent::UUnrealJordakaCameraComponent()
{
}

void UUnrealJordakaCameraComponent::GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView)
{
    AActor* TargetActor = GetOwner();
    APawn* TargetPawn = Cast<APawn>(TargetActor);

    if (TargetPawn != NULL)
    {
        AUnrealJordakaPlayerController* TargetController = TargetPawn->GetController<AUnrealJordakaPlayerController>();

        if (TargetController != NULL)
        {
            FRotator Rotation = FRotator(-80.0f, 0.0f, 0.0f);
            float Offset = 400.0f + TargetController->GetZoomValue() * 600.0f;

            DesiredView.Location = TargetController->GetFocalLocation() - Rotation.Vector() * Offset;
            DesiredView.Rotation = Rotation;
            //DesiredView.FOV = CameraModeView.FieldOfView;
            DesiredView.OrthoWidth = OrthoWidth;
            DesiredView.OrthoNearClipPlane = OrthoNearClipPlane;
            DesiredView.OrthoFarClipPlane = OrthoFarClipPlane;
            DesiredView.AspectRatio = AspectRatio;
            DesiredView.bConstrainAspectRatio = bConstrainAspectRatio;
            DesiredView.bUseFieldOfViewForLOD = bUseFieldOfViewForLOD;
            DesiredView.ProjectionMode = ProjectionMode;
        }
    }
}
