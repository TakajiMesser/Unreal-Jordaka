// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealJordaka : ModuleRules
{
	public UnrealJordaka(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara" });
    }
}
