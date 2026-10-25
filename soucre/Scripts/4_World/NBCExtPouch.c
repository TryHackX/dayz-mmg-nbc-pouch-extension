modded class MMG_nbc_pouch
{
	//! a switched off extra slot takes nothing (checked on the server too)
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!NBCExt_Config.IsSlotEnabled(slotId))
			return false;

		return super.CanReceiveAttachment(attachment, slotId);
	}

	//! a switched off extra slot is hidden - unless something is still stored in it, so it can be taken out
	override bool CanDisplayAttachmentSlot(int slot_id)
	{
		if (!NBCExt_Config.IsSlotEnabled(slot_id) && !GetInventory().FindAttachment(slot_id))
			return false;

		return super.CanDisplayAttachmentSlot(slot_id);
	}
}

modded class PlayerBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type == NBCExt_Config.RPC_SYNC)
			NBCExt_Config.OnReceive(ctx);
	}
}
