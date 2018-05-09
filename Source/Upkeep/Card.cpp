// Fill out your copyright notice in the Description page of Project Settings.

#include "Card.h"


// Sets default values
ACard::ACard()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//RootComponent
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	ConstructorHelpers::FObjectFinder<USkeletalMesh>MeshRef(TEXT("SkeletalMesh'/Game/Upkeep/Meshes/Cards/SM_CardTest.SM_CardTest'"));
	smCardMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CardMeshComponent"));
	smCardMesh->SetupAttachment(RootComponent);
	smCardMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	smCardMesh->SetSkeletalMesh(MeshRef.Object);
}
// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

