// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerMover.h"
#include "Engine.h"

// Sets default values
APlayerMover::APlayerMover()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Root Component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//Static Mesh
	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshRef(TEXT("StaticMesh'/Game/Upkeep/Meshes/Player.Player'"));
	smPlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMeshComponent"));
	smPlayerMesh->SetupAttachment(RootComponent);
	smPlayerMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	smPlayerMesh->SetStaticMesh(MeshRef.Object);

}

// Called when the game starts or when spawned
void APlayerMover::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

