// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Faction.generated.h"


UCLASS()
class UPKEEP_API AFaction : public AActor
{
	GENERATED_BODY()
	
	public:	
		// Sets default values for this actor's properties
		AFaction();
		FName GetName();
		float GetBaseVal();
		float GetInfluenceVal();
	private:
		UPROPERTY(EditAnywhere,SaveGame,meta = (DisplayName = "Base Value",ClampMin = 1))
		float fBaseVal = 1;
		UPROPERTY(EditAnywhere,SaveGame,meta = (DisplayName = "Base Multiplier",ClampMin = 1))
		float fBaseMult = 1;
		UPROPERTY(EditAnywhere,SaveGame,meta = (DisplayName = "Influence Value",ClampMin = 1))
		float fInfuenceVal = 1; 
		UPROPERTY(EditAnywhere,SaveGame,meta = (DisplayName = "Influence Multiplier",ClampMin = 1))
		float fInfluenceMult = 1; 

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:	
		// Called every frame
		virtual void Tick(float DeltaTime) override;

};
