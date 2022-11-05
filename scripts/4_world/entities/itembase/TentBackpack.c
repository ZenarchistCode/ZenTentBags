class TentBackpack extends LargeTentBackPack
{
	string m_PackedTent = "Empty";
	float m_TentHealth;

	// Server-side: set the type of tent contained in this bag, and its health
	void SetTentType(string type, float health)
	{
		m_PackedTent = type;
		m_TentHealth = health;
		SetSynchDirty();
	}

	override void EEOnCECreate()
	{
		super.EEOnCECreate();
		this.SetLifetime(7200);
	}

	override string GetTentType()
	{
		return m_PackedTent;
	}

	float GetTentHealth()
	{
		return m_TentHealth;
	}

	override bool CanDisplayCargo()
	{
		return false;
	}

	string GetTentBagType()
	{
		return "TentBag";
	}

	override void ZenPackTent()
	{
		this.GetInventory().ReplaceItemWithNew(InventoryMode.SERVER, new ReplaceZenTentLambda(this, GetTentBagType(), GetTentType(), GetTentHealth()));
	}

	// If a tent is attached, lock it
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		if (item.IsInherited(TentBase))
		{
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(slot_name), true);
		}
	}

	// Save stuff
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		ctx.Write(m_PackedTent);
		ctx.Write(m_TentHealth);
	}

	// Load stuff
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		bool load = super.OnStoreLoad(ctx, version);

		if (load)
		{
			if (!ctx.Read(m_PackedTent))
			{
				m_PackedTent = "Empty";
			}

			if (!ctx.Read(m_TentHealth))
			{
				m_TentHealth = 0;
			}

			SetTentType(m_PackedTent, m_TentHealth);
		}

		return load;
	}
}

class TentBackpack_Camo extends TentBackpack 
{
	override string GetTentBagType()
	{
		return "TentBag_Camo";
	}
};

class TentBackpack_Arctic extends TentBackpack
{
	override string GetTentBagType()
	{
		return "TentBag_Arctic";
	}
};

class TentBackpack_Desert extends TentBackpack
{
	override string GetTentBagType()
	{
		return "TentBag_Desert";
	}
};

class TentBackpack_Orel extends TentBackpack
{
	override string GetTentBagType()
	{
		return "TentBag_Orel";
	}
};
