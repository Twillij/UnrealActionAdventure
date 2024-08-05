using UnrealBuildTool;
using System.Collections.Generic;

public class ActionAdventureEditorTarget : TargetRules
{
	public ActionAdventureEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("ActionAdventure");
	}
}
