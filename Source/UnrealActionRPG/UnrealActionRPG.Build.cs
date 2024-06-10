// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealActionRPG : ModuleRules
{
	public UnrealActionRPG(ReadOnlyTargetRules Target) : base(Target)
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
			"UnrealActionRPG"
		});
	}
}
