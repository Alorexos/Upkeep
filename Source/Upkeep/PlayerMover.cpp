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

	//Setup Interface
	MyWidget = CreateDefaultSubobject<UWidgetComponent>("Widget");
	static ConstructorHelpers::FClassFinder<UUserWidget> hudWidgetObj(TEXT("'/Game/Upkeep/UI/UI'"));
	if (hudWidgetObj.Succeeded())
	{
		hudWidgetClass = hudWidgetObj.Class;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "SelectableActorHUD not found !");
		hudWidgetClass = nullptr;
	}

	MyWidget->SetWidgetClass(hudWidgetClass);
	MyWidget->SetWidgetSpace(EWidgetSpace::Screen);
	MyWidget->SetDrawSize(FVector2D(1.0, 1.0f));
	MyWidget->SetVisibility(true);
	MyWidget->SetupAttachment(RootComponent);

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

