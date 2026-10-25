modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		NBCExt_Config.Load();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(NBCExt_Config.SendTo, 2000, false, player);
	}
}

modded class MissionGameplay
{
	override void OnInit()
	{
		super.OnInit();

		// offline / listen server
		if (GetGame().IsServer())
			NBCExt_Config.Load();
	}
}
