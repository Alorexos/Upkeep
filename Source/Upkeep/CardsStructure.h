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

	UPROPERTY(EditAnywhere)
		FString Faction;

	UPROPERTY(EditAnywhere)
		FString Character;

	UPROPERTY(EditAnywhere)
		FVector FactionLeft;

	UPROPERTY(EditAnywhere)
		FVector FactionRight;

	UPROPERTY(EditAnywhere)
		FString CardText;

	UPROPERTY(EditAnywhere)
		FString ChoiceRight;

	UPROPERTY(EditAnywhere)
		FString ChoiceLeft;
};
