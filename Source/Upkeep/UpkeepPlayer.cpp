// Fill out your copyright notice in the Description page of Project Settings.

#include "UpkeepPlayer.h"


// Sets default values
AUpkeepPlayer::AUpkeepPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshRef(TEXT("StaticMesh'/Game/Upkeep/Meshes/bb8_Box001.bb8_Box001'"));
	smCardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMeshComponent"));
	smCardMesh->SetupAttachment(RootComponent);
	smCardMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	smCardMesh->SetStaticMesh(MeshRef.Object);
}

// Called when the game starts or when spawned
void AUpkeepPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUpkeepPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUpkeepPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

