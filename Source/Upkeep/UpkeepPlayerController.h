// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UpkeepPlayer.h"
#include "PlayerMover.h"
#include "GameFramework/PlayerController.h"
#include "UpkeepPlayerController.generated.h"

UCLASS()
class UPKEEP_API AUpkeepPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:
		UFUNCTION()
		void SetupPlayerInputComponent();
		void Rotate(float Val);
		void MoveForward(float Val);
		void MoveSideways(float Val);
	private:
		APawn* pPlayerPawn;
		AUpkeepPlayer* pUpkeepPlayer;
		FRotator rotMover;
	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

};
