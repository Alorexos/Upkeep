// Fill out your copyright notice in the Description page of Project Settings.

#include "Choice.h"
#include "Engine.h"


// Sets default values
AChoice::AChoice()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Root Component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshRef(TEXT("StaticMesh'/Game/Upkeep/Meshes/Cards/SM_Card.SM_Card'"));
	smCardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CardMeshComponent"));
	smCardMesh->SetupAttachment(RootComponent);
	smCardMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	smCardMesh->SetStaticMesh(MeshRef.Object);

	//Setup Mouseover
	smCardMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	smCardMesh->OnBeginCursorOver.AddDynamic(this, &AChoice::OnBeginMouseOver);
	smCardMesh->OnEndCursorOver.AddDynamic(this, &AChoice::OnEndMouseOver);
	smCardMesh->OnClicked.AddDynamic(this, &AChoice::OnMouseClick);
	
	MainTextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextComponent"));
	MainTextRender->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
	MainTextRender->SetRelativeLocation(FVector(-1.9, 0.0, 0.01));
	MainTextRender->SetRelativeRotation(FRotator(90.0, 180.0, 0.0));
	MainTextRender->SetWorldSize(0.4);
	MainTextRender->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	MainTextRender->SetVerticalAlignment(EVerticalTextAligment::EVRTA_TextCenter);
	MainTextRender->SetTextRenderColor(FColor::Black);

	//Set Materials
	ConstructorHelpers::FObjectFinder<UMaterial>WrokersMatRef(TEXT("MaterialInstanceConstant'/Game/Upkeep/Materials/Cards/MI_CardWorkers.MI_CardWorkers'"));
	WorkersMat = (UMaterialInterface*)WrokersMatRef.Object;
	ConstructorHelpers::FObjectFinder<UMaterial>ArmyMatRef(TEXT("MaterialInstanceConstant'/Game/Upkeep/Materials/Cards/MI_CardArmy.MI_CardArmy'"));
	ArmyMat = (UMaterialInterface*)ArmyMatRef.Object;
	ConstructorHelpers::FObjectFinder<UMaterial>NoblesMatRef(TEXT("MaterialInstanceConstant'/Game/Upkeep/Materials/Cards/MI_CardNobles.MI_CardNobles'"));
	NoblesMat = (UMaterialInterface*)NoblesMatRef.Object;
}
void AChoice::Initialize(FCardStructure* CardDetails)
{
	pPlayer = (AUpkeepPlayer*)GetWorld()->GetFirstPlayerController()->GetPawn();
	CardHolderComponent = pPlayer->GetCardHolderComponent();
	ChoiceLabel = *this->GetActorLabel();
	this->AttachToComponent((USceneComponent*)CardHolderComponent, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName(*ChoiceLabel));

	//Setup Card Rotation
	float Pitch = 0.f;
	float Roll = 5.f;
	float Yaw = 0.f;
	if (ChoiceLabel == FString("Left Card")) { Yaw = -10.f; }
	if (ChoiceLabel == FString("Right Card")) { Yaw = 10.f; }
	FRotator rotMover = FRotator(Pitch, Yaw, Roll);
	FQuat QuatRotation = FQuat(rotMover);
	this->AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

	//Parameters Setup
	Faction     = CardDetails->Faction;
	MainText    = CardDetails->CardText;
	ChoiceRight = CardDetails->ChoiceRight;
	ChoiceLeft  = CardDetails->ChoiceLeft;

	//Material Setup

	//DynamicMaterial = UMaterialInstanceDynamic::Create(WorkersMat, this);
	//smCardMesh->SetMaterial(0, DynamicMaterial);
}

// Called when the game starts or when spawned
void AChoice::BeginPlay()
{
	Super::BeginPlay();
	FocTranX = 0.0;
	FocTranY = 0.0;
	FocTranZ = 0.0;
	ChoiceThreshold = 3.0f;
	InputComponent = GetWorld()->GetFirstPlayerController()->InputComponent;
	InputComponent->BindAxis("Mouse_Left", this, &AChoice::OnMouseDrag);
}

// Called every frame
void AChoice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AnimateFocused();
	HolderLocation = pPlayer->GetHolderLocation();
}

void AChoice::AnimateFocused()
{
	if (Focused) 
	{
		//FVector Location = this->GetActorLocation();
		
		//Take card out of hand
		//if (Stage1Ticks >= 0)
		//{
		//	float AnimYaw;
		//	Location += this->GetActorForwardVector() * 0.5;
		//	if (ChoiceLabel == FString("Left Card"))
		//	{
		//		AnimYaw = 10.0 / Stage1Ticks;
		//	}
		//	if (ChoiceLabel == FString("Right Card"))
		//	{
		//		AnimYaw = -10.0 / Stage1Ticks;
		//	}
		//	
		//	this->AddActorLocalRotation(FRotator(0.0, AnimYaw, 0.0));
		//	Stage1Ticks -= 1;
		//}
		//else
		//if (Stage2Ticks >= 0)
		//{	
		//	float AnimRoll;
		//	if (ChoiceLabel == FString("Left Card")) 
		//	{ 
		//		AnimRoll = -10.0 / Stage2Ticks;
		//		Location += this->GetActorRightVector() * 0.5f;
		//	}
		//	if (ChoiceLabel == FString("Right Card")) 
		//	{ 
		//		AnimRoll = -10.0 / Stage2Ticks;
		//		Location += this->GetActorRightVector() * -0.5f; 
		//	}
		//	
		//	this->AddActorLocalRotation(FRotator(0.0, 0.0, AnimRoll));
		//	Stage2Ticks -= 1;
		//}


		//Location += this->GetActorUpVector() * 17.f;

		//this->SetActorLocation(Location);


		//if (RelativeRotation.Pitch != 0.0)
		//{
		//	if (this->GetActorRotation().Pitch > 0)
		//	{
		//		this->AddActorRotation(FRotator(-0.1, 0.0, 0.0));
		//	}
		//	if (this->GetActorRotation().Pitch < 0)
		//	{
		//		this->AddActorLocalRotation(FRotator(0.1, 0.0, 0.0));
		//	}
		//}
		//if (this->GetActorRotation().Roll != 0.0)
		//{
		//	if (this->GetActorRotation().Roll > 0)
		//	{
		//		this->AddActorLocalRotation(FRotator(-0.1, 0.0, 0.0));
		//	}
		//	if (this->GetActorRotation().Roll < 0)
		//	{
		//		this->AddActorLocalRotation(FRotator(0.1, 0.0, 0.0));
		//	}
		//}
		//if (this->GetActorRotation().Yaw != 0.0)
		//{
		//	if (this->GetActorRotation().Yaw > 0)
		//	{
		//		this->AddActorLocalRotation(FRotator(-0.1, 0.0, 0.0));
		//	}
		//	if (this->GetActorRotation().Yaw < 0)
		//	{
		//		this->AddActorLocalRotation(FRotator(0.1, 0.0, 0.0));
		//	}
		//}
	}
}

void AChoice::OnBeginMouseOver(UPrimitiveComponent* TouchedComponent)
{
	if (!MouseOverSet)
	{
		if (!Focused)
		{
			FVector NewLocation = this->GetActorLocation();
			NewLocation += this->GetActorForwardVector() * 1.f;
			this->SetActorLocation(NewLocation);
		}
		MouseOverSet = true;
	}
}

void AChoice::OnEndMouseOver(UPrimitiveComponent* TouchedComponent)
{
	if (MouseOverSet)
	{
		if (!Focused)
		{
			FVector NewLocation = this->GetActorLocation();
			NewLocation += this->GetActorForwardVector() * -1.f;
			this->SetActorLocation(NewLocation);
		}
		MouseOverSet = false;
	}
}
void AChoice::OnMouseClick(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	if (!Focused)
	{
		FRotator rotMover = FRotator(0.0, 0.0, 0.0);
		FQuat QuatRotation = FQuat(rotMover);
		this->SetActorRelativeRotation(QuatRotation,false,0, ETeleportType::None);
		FVector NewLocation = this->GetActorLocation();
		NewLocation += this->GetActorForwardVector() * 14.f;
		NewLocation += this->GetActorUpVector() * 17.f;
		if (ChoiceLabel == FString("Left Card")){ NewLocation += this->GetActorRightVector() * 5.f; }
		if (ChoiceLabel == FString("Right Card")) { NewLocation += this->GetActorRightVector() * -5.f; }
		this->SetActorLocation(NewLocation);
		Focused = true;

		//Set Card Main Text
		MainTextRender->SetText(MainText);

	}
	return UFUNCTION() void();
}
void AChoice::OnMouseDrag(float Val)
{	
	//Calculate Card Drag Direction
	FVector DragDifference = this->GetActorLocation() - HolderLocation;
	float dotProd = FVector::DotProduct(this->GetActorRightVector(), DragDifference);


	if ((Focused && Val != 0 && MouseOverSet) || DragStart)
	{
		if (!DragStart)
		{
			DragStartLoc = this->GetActorLocation();
			DragStart = true;
		}
		FVector MouseLoc;
		FVector MouseDir;
		GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(MouseLoc, MouseDir);
		MouseLoc += MouseDir * 5.0f;
		this->SetActorLocation(MouseLoc);

		//Display Choice Text
		if (dotProd > ChoiceThreshold)
		{
			MainTextRender->SetText(ChoiceRight);
		}
		else if (dotProd < - ChoiceThreshold)
		{
			MainTextRender->SetText(ChoiceLeft);
		}
		else
		{
			MainTextRender->SetText(MainText);
		}
	}

	if (Focused && Val == 0 && DragStart)
	{

		if (dotProd > ChoiceThreshold)
		{
			ChoiceMade = true;
			GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, FString("Choice Right"));
		}
		else if (dotProd < - ChoiceThreshold)
		{	
			ChoiceMade = true;
			GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, FString("Choice Left"));
		}
		this->SetActorLocation(DragStartLoc);
		DragStart = false;
	}
}
bool AChoice::GetDecision()
{
	return ChoiceMade;
}

