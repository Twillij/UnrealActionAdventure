using UnrealBuildTool;
using System.Collections.Generic;

public class UnrealActionRPGEditorTarget : TargetRules
{
	public UnrealActionRPGEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("UnrealActionRPG");
	}
}
