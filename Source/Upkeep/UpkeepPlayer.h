// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerMover.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
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
		APlayerMover* GetPlayerMover();

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
		UPROPERTY(EditAnywhere)
		USpringArmComponent* OurCameraSpringArm;
		UCameraComponent* OurCamera;
		UStaticMeshComponent* smPlayerMesh;
		UStaticMesh* MeshRef;
	private:
		APlayerMover* pPlayerMover;


	public:	
		// Called every frame
		virtual void Tick(float DeltaTime) override;

		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
