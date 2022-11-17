// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "UnrealJordakaPlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;

UCLASS()
class AUnrealJordakaPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AUnrealJordakaPlayerController();

	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold;

	/** FX Class that we will spawn when clicking */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UNiagaraSystem* FXCursor;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();

	//void OnMoveX(float Value);
	//void OnMoveY(float Value);

	void OnMoveUpPressed();
	void OnMoveDownPressed();
	void OnMoveRightPressed();
	void OnMoveLeftPressed();
	void OnRunPressed();

	void OnMoveUpReleased();
	void OnMoveDownReleased();
	void OnMoveRightReleased();
	void OnMoveLeftReleased();
	void OnRunReleased();

	void OnTouchPressed(const ETouchIndex::Type FingerIndex, const FVector Location);
	void OnTouchReleased(const ETouchIndex::Type FingerIndex, const FVector Location);

private:
	bool bInputPressed; // Input is bring pressed
	bool bIsTouch; // Is it a touch device
	bool bIsUpPressed;
	bool bIsDownPressed;
	bool bIsRightPressed;
	bool bIsLeftPressed;
	bool bIsRunPressed;
	float FollowTime; // For how long it has been pressed
	
};


