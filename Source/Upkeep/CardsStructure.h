// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "CardsStructure.generated.h"

USTRUCT()
struct FCardStructure : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	/** Category of GamePlay Object */
	UPROPERTY(EditAnywhere, Category = "GO")
	FVector FactionLeft;

	/** Scriptable Use Code */
	UPROPERTY(EditAnywhere, Category = "GO")
		FVector FactionRight;

	/** Category of GamePlay Object */
	UPROPERTY(EditAnywhere, Category = "GO")
		FString CardText;

	/** Scriptable Use Code */
	UPROPERTY(EditAnywhere, Category = "GO")
		FString ChoiceRight;

	/** Scriptable Use Code */
	UPROPERTY(EditAnywhere, Category = "GO")
		FString ChoiceLeft;
};
