// Fill out your copyright notice in the Description page of Project Settings.

#include "UpkeepPlayerController.h"
#include "Engine.h"

void AUpkeepPlayerController::BeginPlay()
{
	Super::BeginPlay();
	pPlayerPawn = GetPawn();
	this->Possess(pPlayerPawn);

	pPlayerPawn->bUseControllerRotationPitch = true;
	pPlayerPawn->bUseControllerRotationRoll = true;
	pPlayerPawn->bUseControllerRotationYaw = true;
	SetupPlayerInputComponent();
}

void AUpkeepPlayerController::SetupPlayerInputComponent()
{
	// set up gameplay key bindings
	EnableInput(this);
	check(InputComponent);
	InputComponent->BindAxis("Rotate_Left", this, &AUpkeepPlayerController::Rotate);
	InputComponent->BindAxis("Rotate_Right", this, &AUpkeepPlayerController::Rotate);
	InputComponent->BindAxis("Move_Forward", this, &AUpkeepPlayerController::Rotate);
	InputComponent->BindAxis("Move_Backward", this, &AUpkeepPlayerController::Rotate);
	InputComponent->BindAxis("Move_Left", this, &AUpkeepPlayerController::Rotate);
	InputComponent->BindAxis("Move_Right", this, &AUpkeepPlayerController::Rotate);

}


void AUpkeepPlayerController::Rotate(float Val)
{
	if (Val != 0.0f)
	{
		if (pPlayerPawn) 
		{
			pPlayerPawn->AddControllerYawInput(Val);
		}
	}
}
