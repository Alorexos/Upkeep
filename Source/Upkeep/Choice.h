// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "UpkeepPlayer.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "Engine/DataTable.h"
#include "CardsStructure.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/TextRenderComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Choice.generated.h"

UCLASS()
class UPKEEP_API AChoice : public AActor
{
	GENERATED_BODY()
	
	public:
		// Sets default values for this actor's properties
		AChoice();

		// Called every frame
		virtual void Tick(float DeltaTime) override;

		// Initial setup of the class outside of constructor
		void Initialize();

		//Function to handle the interaction
		UFUNCTION()
		void OnBeginMouseOver(UPrimitiveComponent* TouchedComponent);
		UFUNCTION()
		void OnEndMouseOver(UPrimitiveComponent* TouchedComponent);
		UFUNCTION()
		void OnMouseClick(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);
		void OnMouseDrag(float Val);
		bool GetDecision();
	private:
		UPROPERTY(EditAnywhere)
	    UStaticMeshComponent* smCardMesh;
		UPROPERTY(EditAnywhere)
		UStaticMesh* MeshRef;
		UPROPERTY(EditAnywhere)
		AUpkeepPlayer* pPlayer;
		UActorComponent* CardHolderComponent;
		UPROPERTY(EditAnywhere)
		FVector PlayerLoc;
		UPROPERTY(EditAnywhere)
		FString ChoiceLabel;
		UPROPERTY(EditAnywhere)
		bool MouseOverSet;
		UPROPERTY(EditAnywhere)
		bool Focused;
		bool ChoiceMade;
		float ChoiceThreshold;

		FVector DragStartLoc;
		bool DragStart;
		FVector HolderLocation;

		//Data Table
		UPROPERTY(EditAnywhere)
		UDataTable* DataTable;

		//Choice Text
		UPROPERTY(EditAnywhere)
		FString MainText;
		UPROPERTY(EditAnywhere)
		FString ChoiceRight;
		UPROPERTY(EditAnywhere)
		FString ChoiceLeft;
		UPROPERTY(EditAnywhere)
		UTextRenderComponent* MainTextRender;

		//Focused variables
		float FocPitch;
		float FocYaw;
		float FocRoll;
		float FocTranX;
		float FocTranY;
		float FocTranZ;
		int Stage1Ticks = 25;
		int Stage2Ticks = 10;
		//Functions 
		void AnimateFocused();
		UInputComponent* InputComponent;



	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:	


	
	
};
