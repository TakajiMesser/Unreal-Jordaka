// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJordakaPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Characters/UnrealJordakaCharacter.h"
#include "Engine/World.h"

AUnrealJordakaPlayerController::AUnrealJordakaPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	bIsSprintPressed = false;
	bIsSneakPressed = false;
}

void AUnrealJordakaPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	APawn* const MyPawn = GetPawn();

	if (MyPawn)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Direction = <%f, %f, 0>"), XValue, YValue);

		FVector MoveDirection = (FVector(UpValue, RightValue, 0)).GetSafeNormal();
		MyPawn->AddMovementInput(MoveDirection, GetMovementScale(), true);

		FHitResult Hit;
		if (GetHitResultUnderCursor(ECC_WorldStatic, false, Hit))
		{
			FVector Location = MyPawn->GetActorLocation();

			FVector2f MousePosition(Hit.Location.X, Hit.Location.Y);
			FVector2f ActorPosition(Location.X, Location.Y);

			FVector2f TurnDirection = (MousePosition - ActorPosition).GetSafeNormal();
			float Yaw = atan2f(TurnDirection.Y, TurnDirection.X);

			FRotator Rotation(0.0, FMath::RadiansToDegrees(Yaw), 0.0);
			MyPawn->SetActorRotation(Rotation);
			//MyPawn->AddControllerYawInput(FMath::RadiansToDegrees(Yaw));
		}
	}

	/*if (bInputPressed)
	{
		FollowTime += DeltaTime;

		// Look for the touch location
		FVector HitLocation = FVector::ZeroVector;
		FHitResult Hit;
		if(bIsTouch)
		{
			GetHitResultUnderFinger(ETouchIndex::Touch1, ECC_Visibility, true, Hit);
		}
		else
		{
			GetHitResultUnderCursor(ECC_Visibility, true, Hit);
		}
		HitLocation = Hit.Location;

		// Direct the Pawn towards that location
		APawn* const MyPawn = GetPawn();
		if(MyPawn)
		{
			FVector WorldDirection = (HitLocation - MyPawn->GetActorLocation()).GetSafeNormal();
			MyPawn->AddMovementInput(WorldDirection, 1.f, false);
		}
	}
	else
	{
		FollowTime = 0.f;
	}*/
}

float AUnrealJordakaPlayerController::GetMovementScale()
{
	if (bIsSprintPressed)
	{
		return 1.f;
	}
	else if (bIsSneakPressed)
	{
		return 0.25f;
	}
	else
	{
		return 0.5f;
	}
}

void AUnrealJordakaPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AUnrealJordakaPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AUnrealJordakaPlayerController::OnSetDestinationReleased);

	InputComponent->BindAxis("MoveUp", this, &AUnrealJordakaPlayerController::OnMoveUp);
	InputComponent->BindAxis("MoveRight", this, &AUnrealJordakaPlayerController::OnMoveRight);
	InputComponent->BindAction("Sprint", IE_Pressed, this, &AUnrealJordakaPlayerController::OnSprintPressed);
	InputComponent->BindAction("Sprint", IE_Released, this, &AUnrealJordakaPlayerController::OnSprintReleased);
	InputComponent->BindAction("Sneak", IE_Pressed, this, &AUnrealJordakaPlayerController::OnSneakPressed);
	InputComponent->BindAction("Sneak", IE_Released, this, &AUnrealJordakaPlayerController::OnSneakReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AUnrealJordakaPlayerController::OnTouchPressed);
	InputComponent->BindTouch(EInputEvent::IE_Released, this, &AUnrealJordakaPlayerController::OnTouchReleased);
}

void AUnrealJordakaPlayerController::OnSetDestinationPressed()
{
	// We flag that the input is being pressed
	bInputPressed = true;
	// Just in case the character was moving because of a previous short press we stop it
	StopMovement();
}

void AUnrealJordakaPlayerController::OnSetDestinationReleased()
{
	// Player is no longer pressing the input
	bInputPressed = false;

	// If it was a short press
	if(FollowTime <= ShortPressThreshold)
	{
		// We look for the location in the world where the player has pressed the input
		FVector HitLocation = FVector::ZeroVector;
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, true, Hit);
		HitLocation = Hit.Location;

		// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, HitLocation);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, HitLocation, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}
}

void AUnrealJordakaPlayerController::OnMoveUp(float Value)
{
	UpValue = Value;
}

void AUnrealJordakaPlayerController::OnMoveRight(float Value)
{
	RightValue = Value;
}

void AUnrealJordakaPlayerController::OnSprintPressed()
{
	bIsSprintPressed = true;
}

void AUnrealJordakaPlayerController::OnSprintReleased()
{
	bIsSprintPressed = false;
}

void AUnrealJordakaPlayerController::OnSneakPressed()
{
	bIsSneakPressed = true;
}

void AUnrealJordakaPlayerController::OnSneakReleased()
{
	bIsSneakPressed = false;
}

void AUnrealJordakaPlayerController::OnTouchPressed(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	bIsTouch = true;
	OnSetDestinationPressed();
}

void AUnrealJordakaPlayerController::OnTouchReleased(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	bIsTouch = false;
	OnSetDestinationReleased();
}
