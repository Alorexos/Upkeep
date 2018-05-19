// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UpkeepPlayer.h"
#include "PlayerMover.h"
#include "UpkeepUI.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "UpkeepPlayerController.generated.h"

UCLASS()
class UPKEEP_API AUpkeepPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:
		AUpkeepPlayerController();
		UFUNCTION()
			void SetupPlayerInputComponent();
		void Rotate(float Val);
		void MoveForward(float Val);
		void MoveSideways(float Val);

		//Interface
		UPROPERTY(EditAnywhere)
			UWidgetComponent* bpInterface;
		UPROPERTY(EditAnywhere)
			UUserWidget* bpInterfaceRef;
		UPROPERTY(EditAnywhere)
			TSubclassOf<UUserWidget> hudWidgetClass;
		UPROPERTY(EditAnywhere)
			UWidgetComponent* MyWidget;

	private:
		APawn* pPlayerPawn;
		AUpkeepPlayer* pUpkeepPlayer;
		FRotator rotMover;

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

};
