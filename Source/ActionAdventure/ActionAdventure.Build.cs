// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ActionAdventure : ModuleRules
{
	public ActionAdventure(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"EnhancedInput",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
			"HeadMountedDisplay",
			"InputCore",
			"OnlineSubsystem",
			"OnlineSubsystemSteam"
		});

		PublicIncludePaths.AddRange(new string[]
		{
			"ActionAdventure"
		});
	}
}
