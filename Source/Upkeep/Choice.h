// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMesh.h"
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
		
	private:
		UPROPERTY(EditAnywhere)
	    USkeletalMeshComponent* smCardMesh;
		UPROPERTY(EditAnywhere)
		USkeletalMesh* MeshRef;
		UPROPERTY(EditAnywhere)
		UActorComponent* pPlayer;
		UPROPERTY(EditAnywhere)
		FVector PlayerLoc;
		UPROPERTY(EditAnywhere)
		FString ChoiceLabel;
		UPROPERTY(EditAnywhere)
		bool MouseOverSet;
		UPROPERTY(EditAnywhere)
		bool Focused;
	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:	


	
	
};
