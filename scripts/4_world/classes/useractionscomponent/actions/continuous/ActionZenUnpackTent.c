class ActionZenUnpackTent : ActionContinuousBase
{
	void ActionZenUnpackTent()
	{
		m_CallbackClass = ActionPackTentCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_2HD;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_Text = "#unbox";
		m_FullBody = true;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (item)
		{
			TentBag bag = TentBag.Cast(item);
			if (bag)
			{
				return bag.ContainsTent();
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
		TentBag bag = TentBag.Cast(action_data.m_MainItem);
		if (!bag || !bag.ContainsTent())
			return;

		TentBase tent = TentBase.Cast(GetGame().CreateObject(bag.GetTentType(), action_data.m_Player.GetPosition()));

		if (tent)
		{
			tent.SetHealth(bag.GetTentHealth());
			bag.SetTentType("Empty", 0);

			// Delete attachment
			GetGame().ObjectDelete(bag.FindAttachmentBySlotName("ZenTentAttachment"));
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