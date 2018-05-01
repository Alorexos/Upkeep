// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Card.generated.h"

UCLASS()
class UPKEEP_API ACard : public APawn
{
	GENERATED_BODY()

	public:
		// Sets default values for this pawn's properties
		ACard();

	private:
		UPROPERTY(EditAnywhere)
		UStaticMeshComponent* smCardMesh;

		UStaticMesh* MeshRef;

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:	
		// Called every frame
		virtual void Tick(float DeltaTime) override;

		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
