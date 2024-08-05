using UnrealBuildTool;
using System.Collections.Generic;

public class ActionAdventureTarget : TargetRules
{
	public ActionAdventureTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("ActionAdventure");
	}
}
