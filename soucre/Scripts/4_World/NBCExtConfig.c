//! Server settings ($profile:MMG_NBC_AntyChem_Extension/config.json) - which extra slots the MMG NBC Pouch has
class NBCExt_Settings
{
	int ConfigVersion = 1;
	//! PO-X Antidote (on by default, like version 1.0)
	bool AntidoteSlot = true;
	//! Chelating Tablets (new, off by default)
	bool ChelatingTabletsSlot = false;
	//! a second gas mask filter (new, off by default)
	bool SpareFilterSlot = false;
}

class NBCExt_Config
{
	static const int RPC_SYNC = 1847261937;
	static const string FOLDER = "$profile:MMG_NBC_AntyChem_Extension";
	static const string FILE = "$profile:MMG_NBC_AntyChem_Extension/config.json";

	protected static ref NBCExt_Settings s_Settings;
	protected static int s_AntidoteSlotId = -2;
	protected static int s_ChelatingSlotId = -2;
	protected static int s_FilterSlotId = -2;

	static NBCExt_Settings Get()
	{
		if (!s_Settings)
			s_Settings = new NBCExt_Settings();
		return s_Settings;
	}

	//! server: read the file, create it with the defaults when it is missing
	static void Load()
	{
		if (!GetGame().IsServer())
			return;

		if (!FileExist(FOLDER))
			MakeDirectory(FOLDER);

		NBCExt_Settings settings = new NBCExt_Settings();
		string error;
		if (FileExist(FILE))
		{
			if (JsonFileLoader<NBCExt_Settings>.LoadFile(FILE, settings, error))
			{
				Print("[MMG_NBC_Extension] Config loaded from " + FILE);
			}
			else
			{
				Print("[MMG_NBC_Extension] ERROR: " + error);
				Print("[MMG_NBC_Extension] Using the default settings, the file was not changed.");
				settings = new NBCExt_Settings();
			}
		}
		else
		{
			if (JsonFileLoader<NBCExt_Settings>.SaveFile(FILE, settings, error))
				Print("[MMG_NBC_Extension] Default config created at " + FILE);
			else
				Print("[MMG_NBC_Extension] ERROR: " + error);
		}

		s_Settings = settings;
		Print("[MMG_NBC_Extension] AntidoteSlot: " + settings.AntidoteSlot.ToString());
		Print("[MMG_NBC_Extension] ChelatingTabletsSlot: " + settings.ChelatingTabletsSlot.ToString());
		Print("[MMG_NBC_Extension] SpareFilterSlot: " + settings.SpareFilterSlot.ToString());
	}

	//! server -> one player (the client hides and blocks the same slots as the server)
	static void SendTo(PlayerBase player)
	{
		if (!GetGame().IsServer() || !player || !player.GetIdentity())
			return;

		NBCExt_Settings settings = Get();
		Param3<bool, bool, bool> data = new Param3<bool, bool, bool>(settings.AntidoteSlot, settings.ChelatingTabletsSlot, settings.SpareFilterSlot);
		GetGame().RPCSingleParam(player, RPC_SYNC, data, true, player.GetIdentity());
	}

	static void OnReceive(ParamsReadContext ctx)
	{
		if (GetGame().IsServer())
			return;

		Param3<bool, bool, bool> data = new Param3<bool, bool, bool>(true, false, false);
		if (!ctx.Read(data))
		{
			Print("[MMG_NBC_Extension] ERROR: could not read the settings from the server");
			return;
		}

		NBCExt_Settings settings = Get();
		settings.AntidoteSlot = data.param1;
		settings.ChelatingTabletsSlot = data.param2;
		settings.SpareFilterSlot = data.param3;
	}

	//! false for an extra slot that is switched off; every other slot of the pouch is left to MMG
	static bool IsSlotEnabled(int slotId)
	{
		if (s_AntidoteSlotId == -2)
		{
			s_AntidoteSlotId = InventorySlots.GetSlotIdFromString("AntiChemInjector");
			s_ChelatingSlotId = InventorySlots.GetSlotIdFromString("nbc_chelating");
			s_FilterSlotId = InventorySlots.GetSlotIdFromString("nbc_filter2");
		}

		NBCExt_Settings settings = Get();
		if (slotId == s_AntidoteSlotId)
			return settings.AntidoteSlot;
		if (slotId == s_ChelatingSlotId)
			return settings.ChelatingTabletsSlot;
		if (slotId == s_FilterSlotId)
			return settings.SpareFilterSlot;

		return true;
	}
}
