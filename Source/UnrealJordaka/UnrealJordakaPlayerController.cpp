// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJordakaPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "UnrealJordakaCharacter.h"
#include "Engine/World.h"

AUnrealJordakaPlayerController::AUnrealJordakaPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	bIsUpPressed = false;
	bIsDownPressed = false;
	bIsRightPressed = false;
	bIsLeftPressed = false;
	bIsRunPressed = false;
}

void AUnrealJordakaPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	APawn* const MyPawn = GetPawn();

	if (MyPawn)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Direction = <%f, %f, 0>"), XValue, YValue);

		/*bool bIsUpPressed;
		bool bIsDownPressed;
		bool bIsRightPressed;
		bool bIsLeftPressed;*/

		float XValue = 0.f;
		if (bIsUpPressed && !bIsDownPressed)
		{
			XValue = 1.f;
		}
		else if (!bIsUpPressed && bIsDownPressed)
		{
			XValue = -1.f;
		}

		float YValue = 0.f;
		if (bIsRightPressed && !bIsLeftPressed)
		{
			YValue = 1.f;
		}
		else if (!bIsRightPressed && bIsLeftPressed)
		{
			YValue = -1.f;
		}

		UPawnMovementComponent* const MovementComponent = MyPawn->GetMovementComponent();
		if (MovementComponent)
		{
			MovementComponent
		}

		FVector Direction = (/*MyPawn->GetActorLocation() + */FVector(XValue, YValue, 0)).GetSafeNormal();

		float ScaleValue = 1.f;
		if (bIsRunPressed)
		{
			ScaleValue = 100.f;
		}

		MyPawn->AddMovementInput(Direction, 1.f, true);
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

void AUnrealJordakaPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AUnrealJordakaPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AUnrealJordakaPlayerController::OnSetDestinationReleased);

	// Set up WASD controls
	//InputComponent->BindAxis("MoveX", this, &AUnrealJordakaPlayerController::OnMoveX);
	//InputComponent->BindAxis("MoveY", this, &AUnrealJordakaPlayerController::OnMoveY);

	InputComponent->BindAction("MoveUp", IE_Pressed, this, &AUnrealJordakaPlayerController::OnMoveUpPressed);
	InputComponent->BindAction("MoveDown", IE_Pressed, this, &AUnrealJordakaPlayerController::OnMoveDownPressed);
	InputComponent->BindAction("MoveRight", IE_Pressed, this, &AUnrealJordakaPlayerController::OnMoveRightPressed);
	InputComponent->BindAction("MoveLeft", IE_Pressed, this, &AUnrealJordakaPlayerController::OnMoveLeftPressed);
	InputComponent->BindAction("Run", IE_Pressed, this, &AUnrealJordakaPlayerController::OnRunPressed);

	InputComponent->BindAction("MoveUp", IE_Released, this, &AUnrealJordakaPlayerController::OnMoveUpReleased);
	InputComponent->BindAction("MoveDown", IE_Released, this, &AUnrealJordakaPlayerController::OnMoveDownReleased);
	InputComponent->BindAction("MoveRight", IE_Released, this, &AUnrealJordakaPlayerController::OnMoveRightReleased);
	InputComponent->BindAction("MoveLeft", IE_Released, this, &AUnrealJordakaPlayerController::OnMoveLeftReleased);
	InputComponent->BindAction("Run", IE_Released, this, &AUnrealJordakaPlayerController::OnRunReleased);

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

/*void AUnrealJordakaPlayerController::OnMoveX(float Value)
{
	if (Value > 0.f)
	{
		UE_LOG(LogTemp, Warning, TEXT("OnMoveX(%f)"), Value);
	}
	
	XValue = Value;
}

void AUnrealJordakaPlayerController::OnMoveY(float Value)
{
	if (Value > 0.f)
	{
		UE_LOG(LogTemp, Warning, TEXT("OnMoveY(%f)"), Value);
	}

	YValue = Value;
}*/

void AUnrealJordakaPlayerController::OnMoveUpPressed()
{
	bIsUpPressed = true;
}

void AUnrealJordakaPlayerController::OnMoveDownPressed()
{
	bIsDownPressed = true;
}

void AUnrealJordakaPlayerController::OnMoveRightPressed()
{
	bIsRightPressed = true;
}

void AUnrealJordakaPlayerController::OnMoveLeftPressed()
{
	bIsLeftPressed = true;
}

void AUnrealJordakaPlayerController::OnRunPressed()
{
	bIsRunPressed = true;
}

void AUnrealJordakaPlayerController::OnMoveUpReleased()
{
	bIsUpPressed = false;
}

void AUnrealJordakaPlayerController::OnMoveDownReleased()
{
	bIsDownPressed = false;
}

void AUnrealJordakaPlayerController::OnMoveRightReleased()
{
	bIsRightPressed = false;
}

void AUnrealJordakaPlayerController::OnMoveLeftReleased()
{
	bIsLeftPressed = false;
}

void AUnrealJordakaPlayerController::OnRunReleased()
{
	bIsRunPressed = false;
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
