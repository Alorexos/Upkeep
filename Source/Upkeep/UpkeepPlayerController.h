// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
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

	private:
		APawn* pPlayerPawn;

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

};
