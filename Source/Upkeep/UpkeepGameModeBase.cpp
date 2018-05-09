// Fill out your copyright notice in the Description page of Project Settings.

#include "UpkeepGameModeBase.h"

AUpkeepGameModeBase::AUpkeepGameModeBase()
{
	DefaultPawnClass = AUpkeepPlayer::StaticClass();
	PlayerControllerClass = AUpkeepPlayerController::StaticClass();
}


