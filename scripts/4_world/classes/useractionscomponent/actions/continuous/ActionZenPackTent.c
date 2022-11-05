class ActionZenPackTent : ActionContinuousBase
{
	void ActionZenPackTent()
	{
		m_CallbackClass = ActionPackTentCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_2HD;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text = "#pack_tent";
		m_FullBody = true;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTCursor(UAMaxDistances.SMALL);
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (item && target && target.GetObject())
		{
			TentBase tent = TentBase.Cast(target.GetObject());
			if (tent)
			{
				TentBag bag = TentBag.Cast(item);
				if (bag)
				{
					return tent.CanBeManipulated() && !bag.ContainsTent() && !tent.IsInherited(TentBag);
				}
			}
		}

		return false;
	}

	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);
		action_data.m_MainItem.SetIsBeingPlaced(true);
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		if (!action_data.m_Target || !action_data.m_Target.GetObject() || !action_data.m_MainItem)
			return;

		// Get tent & bag
		TentBase tent = TentBase.Cast(action_data.m_Target.GetObject());
		TentBag bag = TentBag.Cast(action_data.m_MainItem);

		if (!tent || !bag)
			return;

		// Attach tent to bag
		EntityAI tentAttachment = EntityAI.Cast(bag.GetInventory().CreateInInventory(tent.GetType() + "_Attached"));
		if (tentAttachment)
		{
			bag.SetTentType(tent.GetType(), tent.GetHealth());
			tentAttachment.SetHealth(tent.GetHealth());
			tentAttachment.GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
			GetGame().ObjectDelete(tent);
		}

		// Stop sound
		action_data.m_MainItem.SetIsBeingPlaced(false);
	}

	override void Start(ActionData action_data)
	{
		super.Start(action_data);

		if (action_data.m_Player)
			action_data.m_Player.TryHideItemInHands(true);
	}

	override void OnEnd(ActionData action_data)
	{
		if (action_data.m_Player)
			action_data.m_Player.TryHideItemInHands(false);
	}
};