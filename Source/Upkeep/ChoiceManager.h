// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

//Includes
#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Choice.h" 
#include "ChoiceManager.generated.h"

UCLASS()
class UPKEEP_API AChoiceManager : public AActor
{
	GENERATED_BODY()
	
	public:	
		// Sets default values for this actor's properties
		AChoiceManager();
		void GenerateChoices(bool Clear);

	private:
		int iFactionNo;
		TArray<AChoice*> FactChoice;
		APlayerController* pPlayer;
		FActorSpawnParameters ChoiceParameters;
		FString GetCardName(int CardNum);
	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:	
		// Called every frame
		virtual void Tick(float DeltaTime) override;

	
	
};
