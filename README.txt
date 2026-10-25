MMG NBC Pouch AntyChem Extension & Fix 1.1 - server setup (DayZ 1.30 Badlands)

Requires MMG - Mightys Military Gear (Steam Workshop 2663169692).

1. Add the mod to the server and client -mod parameter (after MMG).
2. Copy keys\TryHackX_New.bikey to your server's "keys" folder.
   (Older versions were signed with TryHackX.bikey - that key is no longer used.)
3. Start the server once - the config is created automatically:
   <server profile>\MMG_NBC_AntyChem_Extension\config.json
   The server sends it to every player on connect - restart the server after editing it.

Extra slots of the MMG NBC Pouch (config.json):
   "AntidoteSlot"          1 = PO-X Antidote slot (default 1 - like version 1.0)
   "ChelatingTabletsSlot"  1 = Chelating Tablets slot (default 0)
   "SpareFilterSlot"       1 = a second gas mask filter slot (default 0)
   A switched off slot is hidden in the inventory and takes nothing. If something is still stored in it
   (the slot was switched off later), the slot stays visible so the item can be taken out.

What MMG itself accepts in the pouch (this mod does not change it):
   NBC hood, jacket, gloves, pants and boots (gray, yellow and the white ones of DayZ 1.30),
   gas masks and one gas mask filter.
   (Version 1.0 patched the gray and yellow clothes one by one - on DayZ 1.30 that made them impossible to wear.)

Works together with Better First Aid (both mods add their own slots to the chelating tablets and filters).
