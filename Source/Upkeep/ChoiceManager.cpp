// Fill out your copyright notice in the Description page of Project Settings.

#include "ChoiceManager.h"
#include "Engine.h"
// Sets default values
AChoiceManager::AChoiceManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	iFactionNo = 3;

	//DataTables Setup
	static ConstructorHelpers::FObjectFinder<UDataTable>DataTableObject(TEXT("DataTable'/Game/Upkeep/DataTables/RandomCards.RandomCards'"));
	if (DataTableObject.Object != nullptr)
	{
		DataTable = DataTableObject.Object;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, FString("DATATABLE OBJECT FAIL"));
	}

}

// Called when the game starts or when spawned
void AChoiceManager::BeginPlay()
{
	Super::BeginPlay();
	GenerateChoices(false);
	GetFactions();
}

// Called every frame
void AChoiceManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for (int i = 0; i < iFactionNo; i++)
	{
		if (FactChoice[i]->GetDecision())
		{
			GenerateChoices(true);
			break;
		}
	}
}

void AChoiceManager::GenerateChoices(bool Clear)
{
	//Clear Array
	if (Clear && FactChoice.Num() != 0)
	{
		for (int i = 0; i < iFactionNo; i++)
		{
			FactChoice[i]->Destroy();
			FactChoice[i] = nullptr;
		}
		FactChoice.Empty(0);
	}

	static const FString ContextString(TEXT("GENERAL"));

	//Populate Array
	for (int i = 0; i < iFactionNo; i++)
	{
		if (DataTable)
		{
			FCardStructure* RandomCardRow = DataTable->FindRow<FCardStructure>(FName(*FString::FromInt(FMath::RandRange(0, 23))), ContextString);
			FactChoice.Add(GetWorld()->SpawnActor<AChoice>(AChoice::StaticClass()));
			FactChoice[i]->SetActorLabel(GetCardName(i));
			FactChoice[i]->Initialize(RandomCardRow);

		}
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

void AChoiceManager::GetFactions()
{
	for (TActorIterator<AFaction> FactionItr(GetWorld()); FactionItr; ++FactionItr)
	{
		Factions.Add(FactionItr->GetActorLabel(), FactionItr->GetPointer());
		GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, FactionItr->GetActorLabel());
	}
}