#pragma once

#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTSingleton.h"
#include "RE/Bethesda/TESBoundObjects.h"
#include "RE/Bethesda/BSExtraData.h"

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
			REL::Relocation<BGSInventoryInterface**> singleton{ REL::ID(501899) };
			return *singleton;
		}

		[[nodiscard]] const BGSInventoryItem* RequestInventoryItem(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::RequestInventoryItem);
			REL::Relocation<func_t> func{ REL::ID(1200959) };
			return func(this, a_handleID);
		}

		[[nodiscard]] bool IsValidHandle(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::IsValidHandle);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3730) };
			return func(this, a_handleID);
		}

		[[nodiscard]] TESBoundObject* GetObjectA(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetObjectA);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3740) };
			return func(this, a_handleID);
		}

		[[nodiscard]] TBO_InstanceData* GetInstanceData(const std::uint32_t& a_handleID, std::uint32_t a_stackID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetInstanceData);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3770) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] const char* GetDisplayFullName(const std::uint32_t& a_handleID, std::uint32_t a_stackID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetDisplayFullName);
			REL::Relocation<func_t> func{ REL::Offset(0x1A37A0) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] std::uint32_t GetItemCount(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetItemCount);
			REL::Relocation<func_t> func{ REL::Offset(0x1A37D0) };
			return func(this, a_handleID);
		}

		[[nodiscard]] bool GetItemHasExtra(const std::uint32_t& a_handleID, std::uint32_t a_stackID, EXTRA_DATA_TYPE a_extraType) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetItemHasExtra);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3800) };
			return func(this, a_handleID, a_stackID, a_extraType);
		}

		[[nodiscard]] ExtraDataList* GetFirstExtra(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetFirstExtra);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3850) };
			return func(this, a_handleID);
		}

		[[nodiscard]] bool IsItemQuestObject(const std::uint32_t& a_handleID, std::uint32_t a_stackID) const
		{
			using func_t = decltype(&BGSInventoryInterface::IsItemQuestObject);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3880) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] TESForm* GetItemOwnership(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetItemOwnership);
			REL::Relocation<func_t> func{ REL::Offset(0x1A38C0) };
			return func(this, a_handleID);
		}

		[[nodiscard]] std::int32_t GetStealValue(const std::uint32_t& a_handleID, std::uint32_t a_stackID, TESObjectREFR* a_ref, std::int32_t a_count, bool a_flag) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetStealValue);
			REL::Relocation<func_t> func{ REL::Offset(0x1A38F0) };
			return func(this, a_handleID, a_stackID, a_ref, a_count, a_flag);
		}

		[[nodiscard]] std::int8_t GetQuickkeyIndex(const std::uint32_t& a_handleID, std::uint32_t a_stackID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetQuickkeyIndex);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3990) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] bool IsFavorite(const std::uint32_t& a_handleID, std::uint32_t a_stackID) const
		{
			using func_t = decltype(&BGSInventoryInterface::IsFavorite);
			REL::Relocation<func_t> func{ REL::Offset(0x1A39C0) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] std::uint32_t FindFeaturedItemStack(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::FindFeaturedItemStack);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3A00) };
			return func(this, a_handleID);
		}

		void SetPlayerHasTakenStack(const std::uint32_t& a_handleID, std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryInterface::SetPlayerHasTakenStack);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3A70) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] std::uint32_t FindStackPlayerHasNotTaken(const std::uint32_t& a_handleID, std::uint32_t& a_stackID) const
		{
			using func_t = decltype(&BGSInventoryInterface::FindStackPlayerHasNotTaken);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3AE0) };
			return func(this, a_handleID, a_stackID);
		}

		[[nodiscard]] bool GetEquippedItemData(const std::uint32_t& a_handleID, std::uint32_t a_stackID, EquippedItemData& a_data) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetEquippedItemData);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3B70) };
			return func(this, a_handleID, a_stackID, a_data);
		}

		void EquipItem(const std::uint32_t& a_handleID, std::uint32_t a_stackID, ExtraDataList* a_extra, bool a_flag, BGSEquipSlot* a_slot, bool a_queueAudio)
		{
			using func_t = decltype(&BGSInventoryInterface::EquipItem);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3C30) };
			return func(this, a_handleID, a_stackID, a_extra, a_flag, a_slot, a_queueAudio);
		}

		void RemoveItemExtraA(const std::uint32_t& a_handleID, EXTRA_DATA_TYPE a_extraType, ExtraDataList* a_extra)
		{
			using func_t = decltype(&BGSInventoryInterface::RemoveItemExtraA);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3C90) };
			return func(this, a_handleID, a_extraType, a_extra);
		}

		void RemoveItemExtraB(const std::uint32_t& a_handleID, EXTRA_DATA_TYPE a_extraType, std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryInterface::RemoveItemExtraB);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3D10) };
			return func(this, a_handleID, a_extraType, a_stackID);
		}

		void ModItemCount(const std::uint32_t& a_handleID, std::int32_t a_delta, std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryInterface::ModItemCount);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3DD0) };
			return func(this, a_handleID, a_delta, a_stackID);
		}

		void SetQuickkeyIndex(const std::uint32_t& a_handleID, std::uint32_t a_stackID, std::int8_t a_index)
		{
			using func_t = decltype(&BGSInventoryInterface::SetQuickkeyIndex);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3E50) };
			return func(this, a_handleID, a_stackID, a_index);
		}

		void ToggleFavorite(const std::uint32_t& a_handleID, std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryInterface::ToggleFavorite);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3EC0) };
			return func(this, a_handleID, a_stackID);
		}

		void ForceMergeStacks(const std::uint32_t& a_handleID)
		{
			using func_t = decltype(&BGSInventoryInterface::ForceMergeStacks);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3F20) };
			return func(this, a_handleID);
		}

		void RemoveAllAgents(ObjectRefHandle a_owner)
		{
			using func_t = decltype(&BGSInventoryInterface::RemoveAllAgents);
			REL::Relocation<func_t> func{ REL::Offset(0x1A3F70) };
			return func(this, a_owner);
		}

		void HandleItemRemoval(ObjectRefHandle a_owner, std::uint32_t a_handleID, std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryInterface::HandleItemRemoval);
			REL::Relocation<func_t> func{ REL::Offset(0x1A4050) };
			return func(this, a_owner, a_handleID, a_stackID);
		}

		void IncRefCount(const std::uint32_t& a_handleID)
		{
			using func_t = decltype(&BGSInventoryInterface::IncRefCount);
			REL::Relocation<func_t> func{ REL::Offset(0x1A4170) };
			return func(this, a_handleID);
		}

		void DecRefCount(const std::uint32_t& a_handleID)
		{
			using func_t = decltype(&BGSInventoryInterface::DecRefCount);
			REL::Relocation<func_t> func{ REL::Offset(0x1A41F0) };
			return func(this, a_handleID);
		}

		// members
		BSTArray<Agent> agentArray;  // B8
	};
	static_assert(sizeof(BGSInventoryInterface) == 0xD0);
}
