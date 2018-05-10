// Fill out your copyright notice in the Description page of Project Settings.

#include "UpkeepPlayer.h"


// Sets default values
AUpkeepPlayer::AUpkeepPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Root Component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	//Static Mesh
	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshRef(TEXT("StaticMesh'/Game/Upkeep/Meshes/Player.Player'"));
	smPlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMeshComponent"));
	smPlayerMesh->SetupAttachment(RootComponent);
	smPlayerMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	smPlayerMesh->SetStaticMesh(MeshRef.Object);

	//Spring Arm
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	OurCameraSpringArm->SetupAttachment(RootComponent);
	OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	OurCameraSpringArm->TargetArmLength = 0.f;
	OurCameraSpringArm->bEnableCameraLag = true;
	OurCameraSpringArm->CameraLagSpeed = 3.0f;
	
	//Camera
	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->SetupAttachment(OurCameraSpringArm, USpringArmComponent::SocketName);
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
	return smPlayerMesh;
}