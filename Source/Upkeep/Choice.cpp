// Fill out your copyright notice in the Description page of Project Settings.

#include "Choice.h"


// Sets default values
AChoice::AChoice()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Choice Created"));
}

// Called when the game starts or when spawned
void AChoice::BeginPlay()
{
	Super::BeginPlay();
	pCard = GetWorld()->SpawnActor<ACard>(ACard::StaticClass());
}

// Called every frame
void AChoice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

