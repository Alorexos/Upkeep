// Fill out your copyright notice in the Description page of Project Settings.

#include "UpkeepPlayerController.h"
#include "Engine.h"
AUpkeepPlayerController::AUpkeepPlayerController()
{
	//Setup Interface
	UWidgetComponent* MyWidget = CreateDefaultSubobject<UWidgetComponent>("Widget");
	static ConstructorHelpers::FClassFinder<UUserWidget> hudWidgetObj(TEXT("'/Game/Upkeep/UI/UI'"));
	if (hudWidgetObj.Succeeded())
	{
		hudWidgetClass = hudWidgetObj.Class;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "SelectableActorHUD not found !");
		hudWidgetClass = nullptr;
	}
	MyWidget->SetWidgetClass(hudWidgetClass);
	MyWidget->SetWidgetSpace(EWidgetSpace::Screen);
	MyWidget->SetRelativeLocation(FVector(0.0, 0.0f, 0.0f));
	MyWidget->SetDrawSize(FVector2D(1.f, 1.0f));
	MyWidget->SetVisibility(true);
	MyWidget->RegisterComponent();
}

void AUpkeepPlayerController::BeginPlay()
{
	Super::BeginPlay();
	pPlayerPawn = GetPawn();
	this->Possess(pPlayerPawn);
	pUpkeepPlayer = (AUpkeepPlayer*) GetPawn();
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bEnableTouchOverEvents = true;
	SetupPlayerInputComponent();
}

void AUpkeepPlayerController::SetupPlayerInputComponent()
{
	// set up gameplay key bindings
	EnableInput(this);
	check(InputComponent);
	InputComponent->BindAxis("Rotate_Left", this, &AUpkeepPlayerController::Rotate);
	InputComponent->BindAxis("Rotate_Right", this, &AUpkeepPlayerController::Rotate);
	InputComponent->BindAxis("Move_Forward", this, &AUpkeepPlayerController::MoveForward);
	InputComponent->BindAxis("Move_Backward", this, &AUpkeepPlayerController::MoveForward);
	InputComponent->BindAxis("Move_Left", this, &AUpkeepPlayerController::MoveSideways);
	InputComponent->BindAxis("Move_Right", this, &AUpkeepPlayerController::MoveSideways);

}


void AUpkeepPlayerController::Rotate(float Val)
{
	if (Val != 0.0f)
	{
		if (pUpkeepPlayer)
		{
			rotMover = FRotator(0.0, Val, 0.0);
			FQuat QuatRotation = FQuat(rotMover);
			pUpkeepPlayer->GetPlayerMover()->AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

		}
	}
}

void AUpkeepPlayerController::MoveForward(float Val)
{
	if (Val != 0.0f)
	{
		if (pUpkeepPlayer)
		{
			FVector NewLocation = pUpkeepPlayer->GetPlayerMover()->GetActorLocation();
			NewLocation += pUpkeepPlayer->GetPlayerMover()->GetActorForwardVector() * Val;
			pUpkeepPlayer->GetPlayerMover()->SetActorLocation(NewLocation);
		}
	}
}

void AUpkeepPlayerController::MoveSideways(float Val)
{
	if (Val != 0.0f)
	{
		if (pUpkeepPlayer)
		{
			FVector NewLocation = pUpkeepPlayer->GetPlayerMover()->GetActorLocation();
			NewLocation += pUpkeepPlayer->GetPlayerMover()->GetActorRightVector() * Val;
			pUpkeepPlayer->GetPlayerMover()->SetActorLocation(NewLocation);
		}
	}
}