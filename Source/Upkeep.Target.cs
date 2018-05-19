// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UpkeepTarget : TargetRules
{
	public UpkeepTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Upkeep", "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Slate", "SlateCore" } );
	}
}
