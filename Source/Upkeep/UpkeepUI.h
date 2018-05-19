// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UpkeepUI.generated.h"

/**
 * 
 */
UCLASS()
class UPKEEP_API UUpkeepUI : public UUserWidget
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interface")
	FString Interface;

};
