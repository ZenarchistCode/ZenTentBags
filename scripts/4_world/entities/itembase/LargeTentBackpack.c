modded class LargeTentBackPack extends Clothing
{
	// Return the classname of the packed tent (for overriding in other tents)
	string GetTentType()
	{
		return "LargeTent";
	}

	// Detect tent backpack being placed anywhere other than the player's back
	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged(oldLoc, newLoc);

		if (GetGame().IsDedicatedServer())
		{
			if (newLoc.GetType() != InventoryLocationType.ATTACHMENT)
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ZenPackTent, 10);
			}
		}
	}

	// Convert this tent backpack back into a packed tent
	void ZenPackTent()
	{
		this.GetInventory().ReplaceItemWithNew(InventoryMode.SERVER, new ReplaceZenTentLambda(this, GetTentType(), GetTentType(), GetHealth()));
	}

	// Only allow attaching empty tent bags or to player
	override bool CanPutAsAttachment(EntityAI parent)
	{
		return super.CanPutAsAttachment(parent) && (GetInventory().CountInventory() == 1 || parent && parent.IsInherited(PlayerBase));
	}
}