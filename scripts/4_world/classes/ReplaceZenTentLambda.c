class ReplaceZenTentLambda : ReplaceItemWithNewLambdaBase
{
	string m_TentType = "Empty";
	float m_TentHealth;

	void ReplaceZenTentLambda(EntityAI old_item, string new_item_type, string tentType, float health)
	{
		m_OldItem = old_item;
		m_NewItemType = new_item_type;
		m_TentType = tentType;
		m_TentHealth = health;
	}

	override void CopyOldPropertiesToNew(notnull EntityAI old_item, EntityAI new_item)
	{
		MiscGameplayFunctions.TransferItemProperties(old_item, new_item);
		MoveInventory(old_item, new_item);

		TentBag bag = TentBag.Cast(new_item);
		if (bag)
		{
			bag.SetTentType(m_TentType, m_TentHealth);
		}
		else
		{
			TentBackpack backpack = TentBackpack.Cast(new_item);
			if (backpack)
			{
				backpack.SetTentType(m_TentType, m_TentHealth);
			}
		}
	}

	static bool MoveInventory(notnull EntityAI oldItem, notnull EntityAI newItem)
	{
		if (!oldItem.GetInventory() || !newItem.GetInventory())
		{
			return false;
		}

		array<EntityAI> children = new array<EntityAI>;
		oldItem.GetInventory().EnumerateInventory(InventoryTraversalType.LEVELORDER, children);
		int count = children.Count();
		float itemHealth;
		bool isRuined, isLocked;
		for (int i = 0; i < count; i++)
		{
			EntityAI child = children.Get(i);
			if (child)
			{
				isRuined = false;
				isLocked = false;
				if (child.IsRuined())
				{
					itemHealth = child.GetHealth("", "");
					child.SetHealthMax("", "");
					isRuined = true;

				}

				if (child.IsLockedInSlot())
				{
					isLocked = true;
				}

				InventoryLocation child_src = new InventoryLocation;
				child.GetInventory().GetCurrentInventoryLocation(child_src);

				InventoryLocation child_dst = new InventoryLocation;
				child_dst.Copy(child_src);
				child_dst.SetParent(newItem);

				if (GameInventory.LocationCanAddEntity(child_dst))
				{
					newItem.GetInventory().TakeToDst(InventoryMode.SERVER, child_src, child_dst);

					if (isRuined)
					{
						child_dst.GetItem().SetHealth("", "", itemHealth);
					}

					if (isLocked)
					{
						ItemBase.Cast(child_dst.GetItem()).LockToParent();
					}
				}
			}
		}

		return true;
	}
};