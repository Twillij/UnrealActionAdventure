// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyActionRPG : ModuleRules
{
	public MyActionRPG(ReadOnlyTargetRules Target) : base(Target)
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
			"InputCore"
		});

		PublicIncludePaths.AddRange(new string[]{"MyActionRPG"});
	}
}
