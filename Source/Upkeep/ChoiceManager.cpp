// Fill out your copyright notice in the Description page of Project Settings.

#include "ChoiceManager.h"

// Sets default values
AChoiceManager::AChoiceManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	iFactionNo = 3;
}

// Called when the game starts or when spawned
void AChoiceManager::BeginPlay()
{
	Super::BeginPlay();
	pPlayer = GetWorld()->GetFirstPlayerController();
	GenerateChoices();
}

// Called every frame
void AChoiceManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AChoiceManager::GenerateChoices()
{
	for (int i = 0; i < iFactionNo; i++)
	{
		FactChoice.Add(GetWorld()->SpawnActor<AChoice>(AChoice::StaticClass()));
		FactChoice[i]->SetActorLabel(GetCardName(i));
		FactChoice[i]->Initialize();
	}
}

FString AChoiceManager::GetCardName(int CardNum)
{
	switch (CardNum)
	{
		case 0: return FString("Right Card");
		break;
		case 1: return FString("Middle Card");
		break;
		case 2: return FString("Left Card");
		break;
		default: return FString("Error");
	}
}