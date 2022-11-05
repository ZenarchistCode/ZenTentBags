modded class JMAnimRegister
{
	override void OnRegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.OnRegisterOneHanded(pType, pBehavior);
		pType.AddItemInHandsProfileIK("TentBag", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/tent_medium_packed.anm");
		//pType.AddItemInHandsProfileIK("LargeTentBackPack", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour, "dz/anims/anm/player/ik/heavy/tent_large.anm");
	}
};