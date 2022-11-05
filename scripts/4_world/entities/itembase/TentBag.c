// This is kinda fucked, but because the tent backpack model doesn't work properly on its own, the only way to use the tent bag model is to inherit from TentBase
// Because the tent bag model actually contains all tent models, not just the bag. So this custom item is basically just a permanently packed Large Tent
class TentBag extends TentBase
{
	bool m_ContainsTent = false;
	string m_PackedTent = "Empty";
	float m_TentHealth;

	void TentBag()
	{
		m_ShowAnimationsWhenPitched.Insert("Body");
		m_ShowAnimationsWhenPitched.Insert("Pack");
		m_ShowAnimationsWhenPacked.Insert("Inventory");
		RegisterNetSyncVariableBool("m_ContainsTent");
	}

	// Causes some weirdness, need to set AddItemInHandsProfileIK to register a heavy item but that means you can't run with the tentbag, and I CBF making a heavy tent bag
	/*override bool IsHeavyBehaviour()
	{
		if (ConfigIsExisting("itemBehaviour"))
			m_ItemBehaviour = ConfigGetInt("itemBehaviour");

		string cfgPath = "CfgVehicles " + m_PackedTent + " itemBehaviour";

		if (!GetGame().ConfigIsExisting(cfgPath))
			return false;

		return GetGame().ConfigGetInt(cfgPath) == 0; // 0 = can't sprint with this tent in your hands (ie. large tent, car tent)
	}*/

	// Detect the tent being placed on a player's back
	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged(oldLoc, newLoc);

		if (GetGame().IsDedicatedServer())
		{
			if (newLoc.GetType() == InventoryLocationType.ATTACHMENT && GetHierarchyParent() && GetHierarchyParent().IsInherited(PlayerBase))
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ConvertToBag, 10);
			}
		}
	}

	// When created by Central Loot Economy, set lifespan to 2 hours. Once manipulated by a player then types.xml lifetime applies.
	override void EEOnCECreate()
	{
		super.EEOnCECreate();
		this.SetLifetime(7200);
	}

	// Only allow attaching empty tent bags or to player
	override bool CanPutAsAttachment(EntityAI parent)
	{
		return super.CanPutAsAttachment(parent) && (GetInventory().CountInventory() == 1 || parent && parent.IsInherited(PlayerBase));
	}

	// Hide tent slot when no tent is attached
	override bool CanDisplayAttachmentSlot(int slot_id)
	{
		string slotID = InventorySlots.GetSlotName(slot_id);

		if (slotID == "ZenTentAttachment")
			return FindAttachmentBySlotName("ZenTentAttachment") != NULL;

		return super.CanDisplayAttachmentSlot(slot_id);
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}

	bool ContainsTent()
	{
		return m_ContainsTent;
	}

	override void SetActions()
	{
		super.SetActions();

		// Remove tent actions
		RemoveAction(ActionTogglePlaceObject);
		RemoveAction(ActionToggleTentOpen);
		RemoveAction(ActionPackTent);
		RemoveAction(ActionDeployObject);

		// Add packing actions
		AddAction(ActionZenPackTent);
		AddAction(ActionZenUnpackTent);
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

	// If tent is detached, unlock slot
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		if (item.IsInherited(TentBase))
		{
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(slot_name), false);
		}
	}

	// Allow attachments
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		return false;
	}

	override bool CanLoadItemIntoCargo(EntityAI item)
	{
		return false;
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		return !IsRuined();
	}

	override bool CanLoadAttachment(EntityAI attachment)
	{
		return !IsRuined();
	}

	override bool CanDisplayCargo()
	{
		return false;
	}

	// Server-side: set the type of tent contained in this bag, and its health
	void SetTentType(string type, float health)
	{
		m_PackedTent = type;
		m_TentHealth = health;

		if (m_PackedTent != "Empty")
		{
			m_ContainsTent = true;
		}
		else
		{
			m_ContainsTent = false;
		}

		SetSynchDirty();
	}

	string GetTentType()
	{
		return m_PackedTent;
	}

	float GetTentHealth()
	{
		return m_TentHealth;
	}

	string GetTentBagType()
	{
		return "TentBackpack";
	}

	void ConvertToBag()
	{
		this.GetInventory().ReplaceItemWithNew(InventoryMode.SERVER, new ReplaceZenTentLambda(this, GetTentBagType(), GetTentType(), GetTentHealth()));
	}

	override void HandleCamoNetAttachment(bool hide)
	{
		// Do nothing. If we allow super() then a giant camo net ghost appears around the bag
	}

	// Don't lock inventory on packed tent bag
	override void Pack(bool update_navmesh, bool init = false)
	{
		HideAllAnimationsAndProxyPhysics();

		m_State = PACKED;
		m_IsEntrance = PACKED;
		m_IsWindow = PACKED;
		m_IsToggle = PACKED;

		Refresh();

		//GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);

		if (update_navmesh)
		{
			RegenerateNavmesh();
		}

		DestroyClutterCutter();

		//if (GetGame().IsDedicatedServer())
		//	MiscGameplayFunctions.DropAllItemsInInventoryInBounds(this, m_HalfExtents);

		SetSynchDirty();

		if (!GetGame().IsDedicatedServer() && !init)
		{
			GetOnViewIndexChanged().Invoke();
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
};

class TentBag_Camo extends TentBag
{
	override string GetTentBagType()
	{
		return "TentBackpack_Camo";
	}
};

class TentBag_Arctic extends TentBag
{
	override string GetTentBagType()
	{
		return "TentBackpack_Arctic";
	}
};

class TentBag_Desert extends TentBag
{
	override string GetTentBagType()
	{
		return "TentBackpack_Desert";
	}
};

class TentBag_Orel extends TentBag
{
	override string GetTentBagType()
	{
		return "TentBackpack_Orel";
	}
};
