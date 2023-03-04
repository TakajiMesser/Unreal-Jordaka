// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJordakaCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Cameras/UnrealJordakaCameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"

AUnrealJordakaCharacter::AUnrealJordakaCharacter()
{
    UE_LOG(LogTemp, Warning, TEXT("Ya lil FLUMBUS"));

    // Set size for player capsule
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

    // Configure character movement
    //GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
    GetCharacterMovement()->RotationRate = FRotator(0.f, 120.f, 0.f);
    GetCharacterMovement()->bConstrainToPlane = true;
    GetCharacterMovement()->bSnapToPlaneAtStart = true;

    // Activate ticking in order to update the cursor every frame.
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;

    CameraComponent = CreateDefaultSubobject<UUnrealJordakaCameraComponent>(TEXT("Camera"));
    CameraComponent->SetRelativeLocation(FVector(-300.0f, 0.0f, 75.0f));

    // Don't rotate character to camera direction
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;
}

void AUnrealJordakaCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}
