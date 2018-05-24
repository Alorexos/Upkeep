// Fill out your copyright notice in the Description page of Project Settings.

#include "UpkeepPlayer.h"


// Sets default values
AUpkeepPlayer::AUpkeepPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Root Component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//Player Static Mesh
	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshRef(TEXT("StaticMesh'/Game/Upkeep/Meshes/Player.Player'"));
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMeshComponent"));
	PlayerMesh->SetupAttachment(RootComponent);
	PlayerMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	PlayerMesh->SetStaticMesh(MeshRef.Object);
	
	//Spring Arm
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("PlayerMoverArm"));
	OurCameraSpringArm->SetupAttachment(RootComponent);
	OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(-30.0f, 0.0f, 0.0f));
	OurCameraSpringArm->TargetArmLength = 700.f;

	//Camera
	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->SetupAttachment(OurCameraSpringArm, USpringArmComponent::SocketName);
	

	//Card Holder Static Mesh
	ConstructorHelpers::FObjectFinder<UStaticMesh>CardHolderMeshRef(TEXT("StaticMesh'/Game/Upkeep/UI/Meshes/SM_CardBorder.SM_CardBorder'"));
	CardHolder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CardHolderMeshComponent"));
	CardHolder->AttachToComponent(OurCameraSpringArm, FAttachmentTransformRules(EAttachmentRule::KeepWorld, false));
	CardHolder->SetRelativeRotation(FRotator(0.f,90.f,70.f));
	CardHolder->SetRelativeLocation(FVector(70.f, 0.f, -28.f));
	CardHolder->SetCollisionProfileName(TEXT("OverlapAll"));
	CardHolder->SetStaticMesh(CardHolderMeshRef.Object);

	//Setup Interface
	MyWidget = CreateDefaultSubobject<UWidgetComponent>("Widget");
	static ConstructorHelpers::FClassFinder<UUserWidget> hudWidgetObj(TEXT("'/Game/Upkeep/UI/UI'"));
	if (hudWidgetObj.Succeeded())
	{
		hudWidgetClass = hudWidgetObj.Class;
	}
	else
	{
		hudWidgetClass = nullptr;
	}

	MyWidget->SetWidgetClass(hudWidgetClass);
	MyWidget->SetWidgetSpace(EWidgetSpace::Screen);
	MyWidget->SetDrawSize(FVector2D(1.0, 1.0f));
	MyWidget->SetVisibility(true);
	MyWidget->SetupAttachment(RootComponent);

	//Take control of the default Player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

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

UStaticMeshComponent* AUpkeepPlayer::GetMeshComponent()
{
	return PlayerMesh;
}

UStaticMeshComponent * AUpkeepPlayer::GetCardHolderComponent()
{
	return CardHolder;
}

