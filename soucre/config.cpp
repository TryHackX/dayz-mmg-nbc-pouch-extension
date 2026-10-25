class CfgPatches
{
    class MMG_NBC_AntyChem_Extension
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DZ_Scripts", "DZ_Gear_Medical", "DZ_Gear_Consumables", "DZ_Gear_Crafting", "jpc_vest"};
    };
};

class CfgMods
{
	class MMG_NBC_Extension
	{
		dir="MMG_NBC_AntyChem_Extension";
		name="MMG - NBC Pouch AntyChem Extension & Fix";
		credits="TryHackX";
		author="TryHackX";
		authorID="76561199846115789";
		version="1.1";
		type="mod";
		dependencies[]={"World","Mission"};

		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]={"MMG_NBC_AntyChem_Extension/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]={"MMG_NBC_AntyChem_Extension/Scripts/5_Mission"};
			};
			class imageSets
			{
				files[]={"MMG_NBC_AntyChem_Extension/gui/imagesets/nbcext_icons.imageset"};
			};
		};
	};
};

// The NBC hood, jacket, gloves, pants and boots (all colours, also the white ones added in DayZ 1.30)
// and the gas masks are accepted by MMG itself. Version 1.0 also patched the gray and yellow clothes
// one by one - on DayZ 1.30 that replaced their normal slots, so they could no longer be worn.
// The extra slots below are switched on/off in the server config (MMG_NBC_AntyChem_Extension/config.json).
class CfgVehicles
{
    class JPCMed_Pouch_base;
    class MMG_nbc_pouch: JPCMed_Pouch_base
    {
        // the spare filter comes first, so it sits right next to MMG's own filter slot
        attachments[] +=
        {
            "nbc_filter2",
            "AntiChemInjector",
            "nbc_chelating"
        };
    };

	// MMG declares the injector with Container_Base - the same base is kept here
	class Container_Base;
    class AntiChemInjector: Container_Base
    {
        inventorySlot[] += 
        {
            "AntiChemInjector"
        };
    };

	// these classes have their own inventorySlot array, so += adds to it
	class Edible_Base;
	class ChelatingTablets: Edible_Base
	{
		inventorySlot[] +=
		{
			"nbc_chelating"
		};
	};

	class Inventory_Base;
	class GasMask_Filter: Inventory_Base
	{
		inventorySlot[] +=
		{
			"nbc_filter2"
		};
	};
	class GasMask_Filter_Improvised: Inventory_Base
	{
		inventorySlot[] +=
		{
			"nbc_filter2"
		};
	};
};

class CfgSlots
{
    class Slot_AntiChemInjector
    {
        name = "AntiChemInjector";
        displayName = "$STR_AntiChemInjector0";
        ghostIcon = "set:jpc_icons image:morphine";
    };
    class Slot_nbc_chelating
    {
        name = "nbc_chelating";
        displayName = "$STR_CfgVehicles_ChelatingTablets0";
        ghostIcon = "set:nbcext_icons image:chelating";
    };
    class Slot_GasMaskFilter;
    class Slot_nbc_filter2: Slot_GasMaskFilter
    {
        name = "nbc_filter2";
    };
};

class CfgNonAIVehicles
{
    class ProxyAttachment;
    class ProxyAntiChemInjector: ProxyAttachment
    {
        scope = 2;
        inventorySlot = "AntiChemInjector";
        model = "\DZ\gear\medical\Morphine.p3d";
    };
};
