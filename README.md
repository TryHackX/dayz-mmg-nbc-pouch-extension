# MMG NBC Pouch AntyChem Extension & Fix

Adds a PO-X Antidote slot and optional slots for Chelating Tablets and a spare gas mask filter to the NBC Pouch of MMG - Mightys Military Gear. For DayZ 1.30 (Badlands).

[Steam Workshop](https://steamcommunity.com/sharedfiles/filedetails/?id=3827411139) · DayZ 1.30 (Badlands) · author: TryHackX

## Support

If the mod is useful for you or your server, you can support further development:

| Currency | Network | Address |
|---|---|---|
| Monero (XMR) | Monero | `45hvee4Jv7qeAm6SrBzXb9YVjb8DkHtFtFh7qkDMxS9zYX3NRi1dV27MtSdVC5X8T1YVoiG8XFiJkh4p9UncqWGxHi4tiwk` |
| Bitcoin (BTC) | Bitcoin (on-chain) | `bc1qncavcek4kknpvykedxas8kxash9kdng990qed2` |
| Ethereum (ETH) | Ethereum (mainnet) | `0xa3d38d5Cf202598dd782C611e9F43f342C967cF5` |

## Features

- The MMG NBC Pouch holds the whole NBC set (hood, jacket, gloves, pants, boots - gray, yellow and the white set of DayZ 1.30, gas masks, filter).
- This mod adds a **PO-X Antidote** slot (on by default) and optional slots for **Chelating Tablets** and a **second gas mask filter** (off by default).
- A switched off slot is hidden and takes nothing; if something is still stored in it, it stays visible so it can be taken out.
- The spare filter slot sits right next to MMG's own filter slot; the Chelating Tablets slot has its own icon.

## Configuration

`<server profile>/MMG_NBC_AntyChem_Extension/config.json` (created on the first start, synced to players):

```json
{
    "ConfigVersion": 1,
    "AntidoteSlot": 1,
    "ChelatingTabletsSlot": 0,
    "SpareFilterSlot": 0
}
```

## Installation

- Requires [MMG - Mightys Military Gear](https://steamcommunity.com/sharedfiles/filedetails/?id=2663169692) (load this mod after MMG).
- Add the mod to the `-mod=` parameter of the server **and** the client.
- Copy `keys/TryHackX_New.bikey` to the `keys` folder of the server.

## Building from source

1. DayZ Tools → **AddonBuilder**: source directory `soucre`, addon prefix `MMG_NBC_AntyChem_Extension`, output `addons/`.
2. Sign the PBO with your own key (DayZ Tools → DSUtils / DSCreateKey + DSSignFile) and give servers your `.bikey`.
   The release on Steam Workshop is signed with `TryHackX_New`.

## Compatibility

- DayZ 1.30 (Badlands), tested on a dedicated server.
- Works together with Better First Aid.

## License

© TryHackX. You are free to use this mod on your server. Please do not repack or reupload it without permission.
