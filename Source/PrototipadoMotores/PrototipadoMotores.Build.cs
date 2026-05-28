// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PrototipadoMotores : ModuleRules
{
	public PrototipadoMotores(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"Niagara"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"PrototipadoMotores",
			"PrototipadoMotores/Variant_Platforming",
			"PrototipadoMotores/Variant_Platforming/Animation",
			"PrototipadoMotores/Variant_Combat",
			"PrototipadoMotores/Variant_Combat/AI",
			"PrototipadoMotores/Variant_Combat/Animation",
			"PrototipadoMotores/Variant_Combat/Gameplay",
			"PrototipadoMotores/Variant_Combat/Interfaces",
			"PrototipadoMotores/Variant_Combat/UI",
			"PrototipadoMotores/Variant_SideScrolling",
			"PrototipadoMotores/Variant_SideScrolling/AI",
			"PrototipadoMotores/Variant_SideScrolling/Gameplay",
			"PrototipadoMotores/Variant_SideScrolling/Interfaces",
			"PrototipadoMotores/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
