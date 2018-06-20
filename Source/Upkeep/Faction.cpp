// Fill out your copyright notice in the Description page of Project Settings.

#include "Faction.h"


// Sets default values
AFaction::AFaction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AActor::SetActorHiddenInGame(true);

}

// Called when the game starts or when spawned
void AFaction::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFaction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FName AFaction::GetName()
{
	return FName(*this->GetActorLabel());
}

float AFaction::GetBaseVal()
{
	return fBaseVal * fBaseMult;
}

float AFaction::GetInfluenceVal()
{
	return fInfuenceVal * fInfluenceMult;
}
AFaction* AFaction::GetPointer()
{
	return this;
}
