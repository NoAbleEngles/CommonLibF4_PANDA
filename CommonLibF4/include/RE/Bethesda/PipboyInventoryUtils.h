#pragma once

#include "RE/Bethesda/TESObjectREFRs.h"

namespace RE
{
	namespace PipboyInventoryUtils
	{
		// Armor slot indices used in Pip-Boy interface
		enum class ArmorSlot : std::uint32_t
		{
			kHead = 0,         // Headwear (hats, helmets, power armor helmet)
			kEyes = 1,         // Eyewear (glasses, goggles)
			kMouth = 2,        // Face covering (gas masks, bandanas)
			kNeck = 3,         // Neck items
			kTorso = 4,        // Torso armor
			kLeftArm = 5,      // Left arm armor
			kRightArm = 6,     // Right arm armor (also includes both arms)
			kLeftLeg = 7,      // Left leg armor
			kRightLeg = 8,     // Right leg armor (also includes both legs)
			kPowerArmor = 0    // Power armor frame (uses head slot detection with special keyword check)
		};

		// BGSBipedObjectForm slot mask bits (44 total slots, indices 30-61 + weapon slots)
		// Based on: https://falloutck.uesp.net/wiki/Biped_Slots
		enum class BipedSlot : std::uint64_t
		{
			kHairTop = 1ULL << 0,        // 30 - Hair Top
			kHairLong = 1ULL << 1,       // 31 - Hair Long
			kFaceGenHead = 1ULL << 2,    // 32 - FaceGen Head
			kBody = 1ULL << 3,           // 33 - BODY (full body/vault suits)
			kLeftHand = 1ULL << 4,       // 34 - Left Hand
			kRightHand = 1ULL << 5,      // 35 - Right Hand
			kUnderTorso = 1ULL << 6,     // 36 - [U] Torso (underwear torso)
			kUnderLeftArm = 1ULL << 7,   // 37 - [U] Left Arm (underwear left arm)
			kUnderRightArm = 1ULL << 8,  // 38 - [U] Right Arm (underwear right arm)
			kUnderLeftLeg = 1ULL << 9,   // 39 - [U] Left Leg (underwear left leg)
			kUnderRightLeg = 1ULL << 10, // 40 - [U] Right Leg (underwear right leg)
			kArmorTorso = 1ULL << 11,    // 41 - [A] Torso (armor torso)
			kArmorLeftArm = 1ULL << 12,  // 42 - [A] Left Arm (armor left arm)
			kArmorRightArm = 1ULL << 13, // 43 - [A] Right Arm (armor right arm)
			kArmorLeftLeg = 1ULL << 14,  // 44 - [A] Left Leg (armor left leg)
			kArmorRightLeg = 1ULL << 15, // 45 - [A] Right Leg (armor right leg)
			kHeadband = 1ULL << 16,      // 46 - Headband (hats/helmets)
			kEyes = 1ULL << 17,          // 47 - Eyes (glasses/goggles)
			kBeard = 1ULL << 18,         // 48 - Beard
			kMouth = 1ULL << 19,         // 49 - Mouth (masks)
			kNeck = 1ULL << 20,          // 50 - Neck
			kRing = 1ULL << 21,          // 51 - Ring
			kScalp = 1ULL << 22,         // 52 - Scalp
			kDecapitation = 1ULL << 23,  // 53 - Decapitation
			kUnnamed1 = 1ULL << 24,      // 54 - Unnamed
			kUnnamed2 = 1ULL << 25,      // 55 - Unnamed
			kUnnamed3 = 1ULL << 26,      // 56 - Unnamed
			kUnnamed4 = 1ULL << 27,      // 57 - Unnamed
			kUnnamed5 = 1ULL << 28,      // 58 - Unnamed
			kShield = 1ULL << 29,        // 59 - Shield
			kPipboy = 1ULL << 30,        // 60 - Pipboy
			kFX = 1ULL << 31,            // 61 - FX

			// Weapon slots (bits 32-43)
			kWeapon1 = 1ULL << 32,
			kWeapon2 = 1ULL << 33,
			kWeapon3 = 1ULL << 34,
			kWeapon4 = 1ULL << 35,
			kWeapon5 = 1ULL << 36,
			kWeapon6 = 1ULL << 37,
			kWeapon7 = 1ULL << 38,
			kWeapon8 = 1ULL << 39,
			kWeapon9 = 1ULL << 40,
			kWeapon10 = 1ULL << 41,
			kWeapon11 = 1ULL << 42,
			kWeapon12 = 1ULL << 43,

			// Convenient masks
			kBodySlots = kUnderTorso | kUnderLeftArm | kUnderRightArm | kUnderLeftLeg | kUnderRightLeg,  // 0x7C0
			kArmorSlots = kArmorTorso | kArmorLeftArm | kArmorRightArm | kArmorLeftLeg | kArmorRightLeg
		};

		constexpr inline const char* SlotToString(BipedSlot slot) {
			switch (slot) {
			case BipedSlot::kHairTop:
				return "Hair Top";
			case BipedSlot::kHairLong:
				return "Hair Long";
			case BipedSlot::kFaceGenHead:
				return "FaceGen Head";
			case BipedSlot::kBody:
				return "Body";
			case BipedSlot::kLeftHand:
				return "Left Hand";
			case BipedSlot::kRightHand:
				return "Right Hand";
			case BipedSlot::kUnderTorso:
				return "Under Torso";
			case BipedSlot::kUnderLeftArm:
				return "Under Left Arm";
			case BipedSlot::kUnderRightArm:
				return "Under Right Arm";
			case BipedSlot::kUnderLeftLeg:
				return "Under Left Leg";
			case BipedSlot::kUnderRightLeg:
				return "Under Right Leg";
			case BipedSlot::kArmorTorso:
				return "Armor Torso";
			case BipedSlot::kArmorLeftArm:
				return "Armor Left Arm";
			case BipedSlot::kArmorRightArm:
				return "Armor Right Arm";
			case BipedSlot::kArmorLeftLeg:
				return "Armor Left Leg";
			case BipedSlot::kArmorRightLeg:
				return "Armor Right Leg";
			case BipedSlot::kHeadband:
				return "Headband";
			case BipedSlot::kEyes:
				return "Eyes";
			case BipedSlot::kBeard:
				return "Beard";
			case BipedSlot::kMouth:
				return "Mouth";
			case BipedSlot::kNeck:
				return "Neck";
			case BipedSlot::kRing:
				return "Ring";
			case BipedSlot::kScalp:
				return "Scalp";
			case BipedSlot::kDecapitation:
				return "Decapitation";
			case BipedSlot::kUnnamed1:
				return "Unnamed1";
			case BipedSlot::kUnnamed2:
				return "Unnamed2";
			case BipedSlot::kUnnamed3:
				return "Unnamed3";
			case BipedSlot::kUnnamed4:
				return "Unnamed4";
			case BipedSlot::kUnnamed5:
				return "Unnamed5";
			case BipedSlot::kShield:
				return "Shield";
			case BipedSlot::kPipboy:
				return "Pipboy";
			case BipedSlot::kFX:
				return "FX";
			case BipedSlot::kWeapon1:
				return "Weapon1";
			case BipedSlot::kWeapon2:
				return "Weapon2";
			case BipedSlot::kWeapon3:
				return "Weapon3";
			case BipedSlot::kWeapon4:
				return "Weapon4";
			case BipedSlot::kWeapon5:
				return "Weapon5";
			case BipedSlot::kWeapon6:
				return "Weapon6";
			case BipedSlot::kWeapon7:
				return "Weapon7";
			case BipedSlot::kWeapon8:
				return "Weapon8";
			case BipedSlot::kWeapon9:
				return "Weapon9";
			case BipedSlot::kWeapon10:
				return "Weapon10";
			case BipedSlot::kWeapon11:
				return "Weapon11";
			case BipedSlot::kWeapon12:
				return "Weapon12";
			case BipedSlot::kBodySlots:
				return "Body Slots (Underwear)";
			case BipedSlot::kArmorSlots:
				return "Armor Slots";
			default:
				return "Unknown";
			}
		}

		inline bool DoSlotsOverlap(const TESObjectARMO* a_armor1, const TESObjectARMO* a_armor2)
		{
			using func_t = decltype(&DoSlotsOverlap);
			REL::Relocation<func_t> func{ REL::ID(1035436) };
			return func(a_armor1, a_armor2);
		}

		inline void FillDamageTypeInfo(const BGSInventoryItem& a_item, const BGSInventoryItem::Stack* a_stack, BSScrapArray<BSTTuple<std::uint32_t, float>>& a_damageValuesPerType)
		{
			using func_t = decltype(&FillDamageTypeInfo);
			REL::Relocation<func_t> func{ REL::ID(928518) };
			return func(a_item, a_stack, a_damageValuesPerType);
		}

		inline void FillResistTypeInfo(const BGSInventoryItem& a_item, const BGSInventoryItem::Stack* a_stack, BSScrapArray<BSTTuple<std::uint32_t, float>>& a_resistValuesPerType, float a_scale)
		{
			using func_t = decltype(&FillResistTypeInfo);
			REL::Relocation<func_t> func{ REL::ID(1578434) };
			return func(a_item, a_stack, a_resistValuesPerType, a_scale);
		}

		// Gets the biped slot mask for an armor piece
		// Returns a 64-bit mask where each bit represents a biped slot (see BipedSlot enum)
		// This calls the virtual function at offset 0x238 in TESObjectARMO's vtable
		// which returns BGSBipedObjectForm::GetSlotMask()
		inline std::uint64_t GetArmorSlotMask(const TESObjectARMO* a_armor)
		{
			if (!a_armor) {
				return 0;
			}

			// Call virtual function GetSlotMask() at vtable offset 0x238
			using func_t = std::uint64_t (*)(const TESObjectARMO*);
			auto vtable = *reinterpret_cast<const void***>(const_cast<TESObjectARMO*>(a_armor));
			auto getSlotMaskFunc = reinterpret_cast<func_t>(vtable[0x238 / 8]);
			return getSlotMaskFunc(a_armor);
		}

		// Checks if the armor matches a specific equipment slot
		// 
		// Slot indices (based on BGSBipedObjectForm slot flags):
		// 0 = Head/Power Armor Frame (checks bits 6-10: 0x7C0, or PowerArmorFrame keyword)
		// 1 = Eyes/Goggles (bit 14: 0x4000)
		// 2 = Mouth/Face (bit 15: 0x8000) 
		// 3 = Neck (bit 12: 0x1000)
		// 4 = Torso/Chest (bit 13: 0x2000)
		// 5 = Left Arm (bit 11: 0x800)
		// 6 = Right Arm/Both Arms (bit 0 or bit 16: 0x10001)
		// 7 = Left Leg (bit 17: 0x20000)
		// 8 = Right Leg/Both Legs (bits 18-19: 0xC0000 both set)
		//
		// Returns true if the armor can be equipped in the specified slot
		inline bool MatchesSlot(const TESObjectARMO* a_armor, std::uint32_t a_slot)
		{
			using func_t = decltype(&MatchesSlot);
			REL::Relocation<func_t> func{ REL::Offset(0x0C0A7D0) };
			return func(a_armor, a_slot);
		}

		// Gets the number of equipment slots that the armor piece occupies
		// Counts individual slots from: arms (L/R), legs (L/R), torso, head, eyes, mouth, neck
		// Returns 5 for power armor frames or underwear (body slot items)
		// Returns count of occupied slots for regular armor pieces
		inline std::uint32_t GetNumSlotMatches(const TESObjectARMO* a_armor)
		{
			using func_t = decltype(&GetNumSlotMatches);
			REL::Relocation<func_t> func{ REL::Offset(0x0C0A960) };
			return func(a_armor);
		}

		// Checks if a bound object is considered underwear (body slot armor pieces like vault suits)
		// Returns true if the item is TESObjectARMO and occupies body slots (bits 6-10: 0x7C0)
		inline bool IsUnderwear(const TESBoundObject* a_object)
		{
			using func_t = decltype(&IsUnderwear);
			REL::Relocation<func_t> func{ REL::Offset(0x0C0AB30) };
			return func(a_object);
		}

		// Checks if a bound object is a vault suit
		// Returns true if the item has the vault suit keyword
		inline bool IsVaultSuit(const TESBoundObject* a_object)
		{
			using func_t = decltype(&IsVaultSuit);
			REL::Relocation<func_t> func{ REL::Offset(0x0C0AB70) };
			return func(a_object);
		}

		// Gets the player's currently equipped underwear type
		// Returns the underwear type enum value
		inline std::uint32_t GetPlayerUnderwearType()
		{
			using func_t = decltype(&GetPlayerUnderwearType);
			REL::Relocation<func_t> func{ REL::Offset(0x0C0ABB0) };
			return func();
		}

		// Gets the equipment state of an inventory item
		// Returns equipment state enum:
		// 0 = not equipped
		// 1 = equipped
		// 2 = equipped (weapon main hand)
		// 3 = equipped (weapon both hands)
		// 4 = equipped (weapon dual wield)
		// 5 = equipped (armor/clothing)
		inline std::uint32_t GetEquipState(const BGSInventoryItem& a_item, const BGSInventoryItem::Stack* a_stack)
		{
			using func_t = decltype(&GetEquipState);
			REL::Relocation<func_t> func{ REL::Offset(0x0C0B4A0) };
			return func(a_item, a_stack);
		}

		// Gets filter flags for an inventory item used in the Pip-Boy UI
		// Returns bitflags indicating item categories:
		// 0x1 = favorited
		// 0x2 = weapons
		// 0x4 = apparel
		// 0x8 = aid
		// 0x200 = misc
		// 0x400 = junk with components
		// 0x800 = holotapes
		// 0x1000 = ammo
		// 0x2000 = mods
		inline std::uint32_t GetFilterFlag(const BGSInventoryItem& a_item, const BGSInventoryItem::Stack* a_stack)
		{
			using func_t = decltype(&GetFilterFlag);
			REL::Relocation<func_t> func{ REL::Offset(0x0C0B610) };
			return func(a_item, a_stack);
		}

		// Compares two float values and returns a comparison difference category
		// a_value: current value
		// a_compareValue: value to compare against
		// Returns:
		// -3 = much worse (< 50%)
		// -2 = worse (50-75%)
		// -1 = slightly worse (75-95%)
		//  0 = same (95-105%)
		//  1 = slightly better (105-125%)
		//  2 = better (125-150%)
		//  3 = much better (> 150%)
		inline std::int32_t GetComparisonDiff(float a_value, float a_compareValue)
		{
			using func_t = decltype(&GetComparisonDiff);
			REL::Relocation<func_t> func{ REL::Offset(0x0C0B750) };
			return func(a_value, a_compareValue);
		}
	}
}
