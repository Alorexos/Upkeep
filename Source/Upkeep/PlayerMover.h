// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/GameFramework/SpringArmComponent.h"
#include "PlayerMover.generated.h"

UCLASS()
class UPKEEP_API APlayerMover : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerMover();
	//Interface
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> hudWidgetClass;
	UPROPERTY(EditAnywhere)
		UWidgetComponent* MyWidget;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UStaticMeshComponent* smPlayerMesh;
	UStaticMesh* MeshRef;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
