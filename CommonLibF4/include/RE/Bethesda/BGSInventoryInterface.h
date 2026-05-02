#pragma once

#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTSingleton.h"
#include "RE/Bethesda/TESBoundObjects.h"
#include "RE/Bethesda/BSExtraData.h"

#include "REL/IDSelection.h"
#include "RE/RTTI_IDs.h"
#include "RE/RTTI_IDs_AE.h"
#include "RE/VTABLE_IDs.h"
#include "RE/VTABLE_IDs_AE.h"

namespace RE
{
	class BGSInventoryItem;

	namespace InventoryInterface
	{
		struct CountChangedEvent
		{
		public:
			// members
			std::uint32_t inventoryOwnerID;  // 00
			std::uint32_t itemID;            // 04
			std::int32_t newCount;           // 08
			std::int32_t oldCount;           // 0C
		};
		static_assert(sizeof(CountChangedEvent) == 0x10);

		struct FavoriteChangedEvent
		{
		public:
			~FavoriteChangedEvent() noexcept {}  // intentional

			// members
			BGSInventoryItem* itemAffected;  // 0
		};
		static_assert(sizeof(FavoriteChangedEvent) == 0x8);

		struct Handle
		{
		public:
			~Handle() noexcept {}  // intentional

			// members
			std::uint32_t id;  // 0
		};
		static_assert(sizeof(Handle) == 0x4);
	}

	class BGSInventoryInterface :
		BSTSingletonSDM<BGSInventoryInterface>,                   // 00
		BSTEventSource<InventoryInterface::CountChangedEvent>,    // 08
		BSTEventSource<InventoryInterface::FavoriteChangedEvent>  // 60
	{
	public:
		struct Agent
		{
		public:
			// members
			std::uint32_t handleID;     // 0
			ObjectRefHandle itemOwner;  // 4
			std::uint16_t listIndex;    // 8
			std::uint16_t refCount;     // A
		};
		static_assert(sizeof(Agent) == 0xC);

		struct EquippedItemData
		{
		public:
			EquippedItemData() {}
		};

		[[nodiscard]] static BGSInventoryInterface* GetSingleton()
		{
			REL::Relocation<BGSInventoryInterface**> singleton{ REL::SelectVersionID(501899, 4796586) };
			return *singleton;
		}

		[[nodiscard]] const BGSInventoryItem* RequestInventoryItem(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::RequestInventoryItem);
			REL::Relocation<func_t> func{ REL::SelectVersionID(1200959, 2194009) };
			return func(this, a_handleID);
		}

		[[nodiscard]] bool IsValidHandle(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::IsValidHandle);
			REL::Relocation<func_t> func{ REL::SelectVersionID(1014178, 2194010) };
			return func(this, a_handleID);
		}

		[[nodiscard]] TESBoundObject* GetObjectA(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetObjectA);
			REL::Relocation<func_t> func{ REL::SelectVersionID(1453201, 2194011) };
			return func(this, a_handleID);
		}

		[[nodiscard]] TBO_InstanceData* GetInstanceData(const std::uint32_t& a_handleID, std::uint32_t a_stackID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetInstanceData);
			REL::Relocation<func_t> func{ REL::SelectVersionID(1187097, 2194012) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] const char* GetDisplayFullName(const std::uint32_t& a_handleID, std::uint32_t a_stackID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetDisplayFullName);
			REL::Relocation<func_t> func{ REL::SelectVersionID(920960, 2194013) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] std::uint32_t GetItemCount(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetItemCount);
			REL::Relocation<func_t> func{ REL::SelectVersionID(655370, 2194014) };
			return func(this, a_handleID);
		}

		[[nodiscard]] bool GetItemHasExtra(const std::uint32_t& a_handleID, std::uint32_t a_stackID, EXTRA_DATA_TYPE a_extraType) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetItemHasExtra);
			REL::Relocation<func_t> func{ REL::SelectVersionID(388957, 2194015) };
			return func(this, a_handleID, a_stackID, a_extraType);
		}

		[[nodiscard]] ExtraDataList* GetFirstExtra(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetFirstExtra);
			REL::Relocation<func_t> func{ REL::SelectVersionID(1000368, 2194016) };
			return func(this, a_handleID);
		}

		[[nodiscard]] bool IsItemQuestObject(const std::uint32_t& a_handleID, std::uint32_t a_stackID) const
		{
			using func_t = decltype(&BGSInventoryInterface::IsItemQuestObject);
			REL::Relocation<func_t> func{ REL::SelectVersionID(734904, 2194017) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] TESForm* GetItemOwnership(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetItemOwnership);
			REL::Relocation<func_t> func{ REL::SelectVersionID(907343, 2194018) };
			return func(this, a_handleID);
		}

		[[nodiscard]] std::int32_t GetStealValue(const std::uint32_t& a_handleID, std::uint32_t a_stackID, TESObjectREFR* a_ref, std::int32_t a_count, bool a_flag) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetStealValue);
			REL::Relocation<func_t> func{ REL::SelectVersionID(641537, 2194019) };
			return func(this, a_handleID, a_stackID, a_ref, a_count, a_flag);
		}

		[[nodiscard]] std::int8_t GetQuickkeyIndex(const std::uint32_t& a_handleID, std::uint32_t a_stackID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetQuickkeyIndex);
			REL::Relocation<func_t> func{ REL::SelectVersionID(641537, 2194020) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] bool IsFavorite(const std::uint32_t& a_handleID, std::uint32_t a_stackID) const
		{
			using func_t = decltype(&BGSInventoryInterface::IsFavorite);
			REL::Relocation<func_t> func{ REL::SelectVersionID(15555, 2194021) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] std::uint32_t FindFeaturedItemStack(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::FindFeaturedItemStack);
			REL::Relocation<func_t> func{ REL::SelectVersionID(189096, 2194022) };
			return func(this, a_handleID);
		}

		void SetPlayerHasTakenStack(const std::uint32_t& a_handleID, std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryInterface::SetPlayerHasTakenStack);
			REL::Relocation<func_t> func{ REL::SelectVersionID(95528, 2194023) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] std::uint32_t FindStackPlayerHasNotTaken(const std::uint32_t& a_handleID, std::uint32_t& a_stackID) const
		{
			using func_t = decltype(&BGSInventoryInterface::FindStackPlayerHasNotTaken);
			REL::Relocation<func_t> func{ REL::SelectVersionID(1669, 2194024) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] bool GetEquippedItemData(const std::uint32_t& a_handleID, std::uint32_t a_stackID, EquippedItemData& a_data) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetEquippedItemData);
			REL::Relocation<func_t> func{ REL::SelectVersionID(786764, 2194025) };
			return func(this, a_handleID, a_stackID, a_data);
		}

		void EquipItem(const std::uint32_t& a_handleID, std::uint32_t a_stackID, ExtraDataList* a_extra, bool a_flag, BGSEquipSlot* a_slot, bool a_queueAudio)
		{
			using func_t = decltype(&BGSInventoryInterface::EquipItem);
			REL::Relocation<func_t> func{ REL::SelectVersionID(1304700, 2194026) };
			return func(this, a_handleID, a_stackID, a_extra, a_flag, a_slot, a_queueAudio);
		}

		void RemoveItemExtraA(const std::uint32_t& a_handleID, EXTRA_DATA_TYPE a_extraType, ExtraDataList* a_extra)
		{
			using func_t = decltype(&BGSInventoryInterface::RemoveItemExtraA);
			REL::Relocation<func_t> func{ REL::SelectVersionID(773024, 2194027) };
			return func(this, a_handleID, a_extraType, a_extra);
		}

		void RemoveItemExtraB(const std::uint32_t& a_handleID, EXTRA_DATA_TYPE a_extraType, std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryInterface::RemoveItemExtraB);
			REL::Relocation<func_t> func{ REL::SelectVersionID(1118198, 2194028) };
			return func(this, a_handleID, a_extraType, a_stackID);
		}

		void ModItemCount(const std::uint32_t& a_handleID, std::int32_t a_delta, std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryInterface::ModItemCount);
			REL::Relocation<func_t> func{ REL::SelectVersionID(54170, 2194029) };
			return func(this, a_handleID, a_delta, a_stackID);
		}

		void SetQuickkeyIndex(const std::uint32_t& a_handleID, std::uint32_t a_stackID, std::int8_t a_index)
		{
			using func_t = decltype(&BGSInventoryInterface::SetQuickkeyIndex);
			REL::Relocation<func_t> func{ REL::SelectVersionID(399651, 2194030) };
			return func(this, a_handleID, a_stackID, a_index);
		}

		void ToggleFavorite(const std::uint32_t& a_handleID, std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryInterface::ToggleFavorite);
			REL::Relocation<func_t> func{ REL::SelectVersionID(306438, 2194031) };
			return func(this, a_handleID, a_stackID);
		}

		void ForceMergeStacks(const std::uint32_t& a_handleID)
		{
			using func_t = decltype(&BGSInventoryInterface::ForceMergeStacks);
			REL::Relocation<func_t> func{ REL::SelectVersionID(1356509, 2194032) };
			return func(this, a_handleID);
		}

		void RemoveAllAgents(ObjectRefHandle a_owner)
		{
			using func_t = decltype(&BGSInventoryInterface::RemoveAllAgents);
			REL::Relocation<func_t> func{ REL::SelectVersionID(385955, 2194033) };
			return func(this, a_owner);
		}

		void HandleItemRemoval(ObjectRefHandle a_owner, std::uint32_t a_handleID, std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryInterface::HandleItemRemoval);
			REL::Relocation<func_t> func{ REL::SelectVersionID(199722, 2194034) };
			return func(this, a_owner, a_handleID, a_stackID);
		}

		void IncRefCount(const std::uint32_t& a_handleID)
		{
			using func_t = decltype(&BGSInventoryInterface::IncRefCount);
			REL::Relocation<func_t> func{ REL::SelectVersionID(186020, 2194035) };
			return func(this, a_handleID);
		}

		void DecRefCount(const std::uint32_t& a_handleID)
		{
			using func_t = decltype(&BGSInventoryInterface::DecRefCount);
			REL::Relocation<func_t> func{ REL::SelectVersionID(531434, 2194036) };
			return func(this, a_handleID);
		}

		// members
		BSTArray<Agent> agentArray;  // B8
	};
	static_assert(sizeof(BGSInventoryInterface) == 0xD0);
}
