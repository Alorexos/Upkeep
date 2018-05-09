// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMesh.h"
#include "Card.generated.h"

UCLASS()
class UPKEEP_API ACard : public AActor
{
	GENERATED_BODY()

	public:
		// Sets default values for this pawn's properties
		ACard();

	private:
		UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* smCardMesh;
		USkeletalMesh* MeshRef;

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:	
		// Called every frame
		virtual void Tick(float DeltaTime) override;

};
