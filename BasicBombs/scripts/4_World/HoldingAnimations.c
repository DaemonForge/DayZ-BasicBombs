modded class ModItemRegisterCallbacks
{
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);
		pType.AddItemInHandsProfileIK("BB_PipeCap", "dz/anims/workspaces/player/player_main/props/player_main_1h_lighter.asi", pBehavior,	"dz/anims/anm/player/ik/gear/petrol_lighter.anm");
		pType.AddItemInHandsProfileIK("BB_PipeBomb_Shell", "dz/anims/workspaces/player/player_main/props/player_main_1h_crowbar.asi", pBehavior,	"dz/anims/anm/player/ik/gear/hatchet.anm");
		pType.AddItemInHandsProfileIK("BB_PipeBomb", "dz/anims/workspaces/player/player_main/props/player_main_1h_crowbar.asi", pBehavior,	"dz/anims/anm/player/ik/gear/hatchet.anm");
	};
};