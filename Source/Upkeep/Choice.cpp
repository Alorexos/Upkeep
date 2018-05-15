// Fill out your copyright notice in the Description page of Project Settings.

#include "Choice.h"
#include "Engine.h"

// Sets default values
AChoice::AChoice()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//RootComponent
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	ConstructorHelpers::FObjectFinder<USkeletalMesh>MeshRef(TEXT("SkeletalMesh'/Game/Upkeep/Meshes/Cards/SM_CardTest.SM_CardTest'"));
	smCardMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CardMeshComponent"));
	smCardMesh->SetupAttachment(RootComponent);
	smCardMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	smCardMesh->SetSkeletalMesh(MeshRef.Object);

	//Setup Mouseover
	smCardMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	smCardMesh->OnBeginCursorOver.AddDynamic(this, &AChoice::CustomOnBeginMouseOver);
}

void AChoice::Initialize()
{
	pPlayer = GetWorld()->GetFirstPlayerController()->GetPawn()->FindComponentByClass(UStaticMeshComponent::StaticClass());
	ChoiceLabel = *this->GetActorLabel();
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, ChoiceLabel);
	this->AttachToComponent((USceneComponent*)pPlayer, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName(*ChoiceLabel));
}

// Called when the game starts or when spawned
void AChoice::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AChoice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AChoice::CustomOnBeginMouseOver(UPrimitiveComponent* TouchedComponent)
{
		GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Cyan, TEXT("Mouse Over"));
}