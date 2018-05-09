// Fill out your copyright notice in the Description page of Project Settings.

#include "Choice.h"
#include "Engine.h"

// Sets default values
AChoice::AChoice()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AChoice::Initialize(APlayerController* pPlayerRef)
{

}

// Called when the game starts or when spawned
void AChoice::BeginPlay()
{
	Super::BeginPlay();
	pCard = GetWorld()->SpawnActor<ACard>(ACard::StaticClass());
	pPlayer = GetWorld()->GetFirstPlayerController()->GetPawn()->FindComponentByClass(UStaticMeshComponent::StaticClass());
	ChoiceLabel = *this->GetActorLabel();
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, ChoiceLabel);
	if (ChoiceLabel == FString("Choice"))
	{
		pCard->AttachToComponent((USceneComponent*)pPlayer,FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true),FName("Right Card"));
	}
	else if (ChoiceLabel == FString("Choice1"))
	{
		pCard->AttachToComponent((USceneComponent*)pPlayer,FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true),FName("Middle Card"));
	}
	else if (ChoiceLabel == FString("Choice2"))
	{
		pCard->AttachToComponent((USceneComponent*)pPlayer,FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true),FName("Left Card"));
	}
}

// Called every frame
void AChoice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//pPlayer = GetWorld()->GetFirstPlayerController()->GetPawn();
	//PlayerLoc = pPlayer->GetActorLocation();
}