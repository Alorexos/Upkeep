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
	smCardMesh->OnBeginCursorOver.AddDynamic(this, &AChoice::OnBeginMouseOver);
	smCardMesh->OnEndCursorOver.AddDynamic(this, &AChoice::OnEndMouseOver);

	
}
void AChoice::Initialize()
{
	pPlayer = GetWorld()->GetFirstPlayerController()->GetPawn()->FindComponentByClass(UStaticMeshComponent::StaticClass());
	ChoiceLabel = *this->GetActorLabel();
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, ChoiceLabel);
	this->AttachToComponent((USceneComponent*)pPlayer, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName(*ChoiceLabel));

	//Setup Card Rotation
	float Pitch = 0.f;
	float Roll = 5.f;
	float Yaw = 0.f;
	if (ChoiceLabel == FString("Left Card")) { Yaw = -10.f; }
	if (ChoiceLabel == FString("Right Card")) { Yaw = 10.f; }
	FRotator rotMover = FRotator(Pitch, Yaw, Roll);
	FQuat QuatRotation = FQuat(rotMover);
	this->AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
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

void AChoice::OnBeginMouseOver(UPrimitiveComponent* TouchedComponent)
{
	if (!MouseOverSet && !Focused)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Cyan, TEXT("MouseOver = " + ChoiceLabel));
		FVector NewLocation = this->GetActorLocation();
		NewLocation += this->GetActorForwardVector() * 1.f;
		this->SetActorLocation(NewLocation);
		MouseOverSet = true;
	}
	
}

void AChoice::OnEndMouseOver(UPrimitiveComponent* TouchedComponent)
{
	if (MouseOverSet && !Focused)
	{
		FVector NewLocation = this->GetActorLocation();
		NewLocation += this->GetActorForwardVector() * -1.f;
		this->SetActorLocation(NewLocation);
		MouseOverSet = false;
	}
}
void AChoice::OnMouseClick(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Cyan, TEXT("Mouse Click = " + ButtonPressed.ToString()));
	if (!Focused && MouseOverSet)
	{
		FRotator rotMover = FRotator(0.0, 0.0, 0.0);
		FQuat QuatRotation = FQuat(rotMover);
		this->SetActorRelativeRotation(QuatRotation,false,0, ETeleportType::None);
		FVector NewLocation = this->GetActorLocation();
		NewLocation += this->GetActorForwardVector() * 13.f;
		NewLocation += this->GetActorUpVector() * 15.f;
		if (ChoiceLabel == FString("Left Card")){ NewLocation += this->GetActorRightVector() * 5.f; }
		if (ChoiceLabel == FString("Right Card")) { NewLocation += this->GetActorRightVector() * -5.f; }
		this->SetActorLocation(NewLocation);
		Focused = true;
	}
	return UFUNCTION() void();
}

