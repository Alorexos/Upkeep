// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/GameFramework/SpringArmComponent.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/GameFramework/SpringArmComponent.h"
#include "UpkeepPlayer.generated.h"

UCLASS()
class UPKEEP_API AUpkeepPlayer : public APawn
{
	GENERATED_BODY()

	public:
		// Sets default values for this pawn's properties
		AUpkeepPlayer();
		UStaticMeshComponent* GetMeshComponent();
		UStaticMeshComponent* GetCardHolderComponent();
		FVector GetHolderLocation();

		//Interface
		UPROPERTY(EditAnywhere)
			TSubclassOf<UUserWidget> hudWidgetClass;
		UPROPERTY(EditAnywhere)
			UWidgetComponent* MyWidget;

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
		UPROPERTY(EditAnywhere)
		UCameraComponent* OurCamera;
		UPROPERTY(EditAnywhere)
		USpringArmComponent* OurCameraSpringArm;

		// Mesh variables
	    UStaticMesh* MeshRef;
		UStaticMesh* CardHolderMeshRef;
		UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PlayerMesh;
		UPROPERTY(EditAnywhere)
		UStaticMeshComponent* CardHolder;
	private:
		


	public:	
		// Called every frame
		virtual void Tick(float DeltaTime) override;

		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
