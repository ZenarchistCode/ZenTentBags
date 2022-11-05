modded class TentBase
{
	// Force tents to re-spawn every 4 hours when they are created by the Central Loot Economy (once touched by players, regular types.xml lifetime applies)
	override void EEOnCECreate()
	{
		super.EEOnCECreate();
		this.SetLifetime(14400);
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}

	// If tent is attached to tent bag, return a different inventory view than whatever fucked one is usually given
	override int GetViewIndex()
	{
		if (MemoryPointExists("invView2"))
		{
			InventoryLocation il = new InventoryLocation;
			GetInventory().GetCurrentInventoryLocation(il);
			InventoryLocationType type = il.GetType();

			if (GetState() == PACKED && type == InventoryLocationType.ATTACHMENT && GetHierarchyParent())
			{
				return 0;
			}
		}

		return super.GetViewIndex();
	}
};