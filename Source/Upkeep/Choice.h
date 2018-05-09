// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Card.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "Choice.generated.h"

UCLASS()
class UPKEEP_API AChoice : public AActor
{
	GENERATED_BODY()
	
	public:
		// Sets default values for this actor's properties
		AChoice();
		void Initialize(APlayerController* pPlayerRef);
	private:
		ACard* pCard;
		UActorComponent* pPlayer;
		FVector PlayerLoc;
		FString ChoiceLabel;
	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:	
		// Called every frame
		virtual void Tick(float DeltaTime) override;

	
	
};
