#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/NetImmerse/NiObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class __declspec(novtable) NiExtraData :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiExtraData };
		static constexpr auto VTABLE{ VTABLE::NiExtraData };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiExtraData };

		// NiExtraData();
		virtual ~NiExtraData() {};  // 00

		// add
		virtual bool KeepForExport() const { return false; }        // 28
		virtual bool KeepForExporterOnly() const { return false; }  // 29
		virtual bool IsStreamable() const { return true; }          // 2A
		virtual bool IsCloneable() const { return true; }           // 2B
		virtual NiExtraData* CreateClone() = 0;  // 26

		F4_HEAP_REDEFINE_NEW(NiExtraData);

		[[nodiscard]] std::string_view GetName() const { return name; }

		// members
		BSFixedString name;  // 10
	};
	static_assert(sizeof(NiExtraData) == 0x18);

	class NiExtraDataContainer
	{
	public:
		//NiExtraDataContainer();
		//NiExtraDataContainer(std::uint32_t a_size);
		~NiExtraDataContainer() {};

		F4_HEAP_REDEFINE_NEW(NiExtraDataContainer);

		void Add(NiPointer<NiExtraData> a_extraData)
		{
			using func_t = decltype(&NiExtraDataContainer::Add);
			REL::Relocation<func_t> func{ REL::Offset(0x1B98220) };  // Add function
			return func(this, a_extraData);
		}

		[[nodiscard]] NiExtraData* GetAt(std::uint32_t a_index) const
		{
			using func_t = decltype(&NiExtraDataContainer::GetAt);
			REL::Relocation<func_t> func{ REL::Offset(0x693E20) };  // GetAt function
			return func(this, a_index);
		}

		[[nodiscard]] std::uint32_t GetSize() const
		{
			using func_t = decltype(&NiExtraDataContainer::GetSize);
			REL::Relocation<func_t> func{ REL::Offset(0x693FC0) };  // GetSize function
			return func(this);
		}

		[[nodiscard]] std::uint32_t FindIndex(const BSFixedString& a_name) const
		{
			using func_t = decltype(&NiExtraDataContainer::FindIndex);
			REL::Relocation<func_t> func{ REL::Offset(0x1B969F0) };  // FindIndex function
			return func(this, a_name);
		}

		[[nodiscard]] NiExtraData* GetByName(const BSFixedString& a_name) const
		{
			auto index = FindIndex(a_name);
			if (index != static_cast<std::uint32_t>(-1)) {
				return GetAt(index);
			}
			return nullptr;
		}

		void Remove(std::uint32_t a_index)
		{
			using func_t = decltype(&NiExtraDataContainer::Remove);
			REL::Relocation<func_t> func{ REL::Offset(0x1B96980) };  // Remove function
			return func(this, a_index);
		}

		void Clone(const NiExtraDataContainer& a_source)
		{
			using func_t = decltype(&NiExtraDataContainer::Clone);
			REL::Relocation<func_t> func{ REL::Offset(0x1B96700) };  // Clone function
			return func(this, a_source);
		}

		void ProcessClone(const NiExtraDataContainer& a_source)
		{
			using func_t = decltype(&NiExtraDataContainer::ProcessClone);
			REL::Relocation<func_t> func{ REL::Offset(0x1B96910) };  // ProcessClone function
			return func(this, a_source);
		}

		void MoveExtras(NiExtraDataContainer& a_source)
		{
			using func_t = decltype(&NiExtraDataContainer::MoveExtras);
			REL::Relocation<func_t> func{ REL::Offset(0x1B96B10) };  // MoveExtras function
			return func(this, a_source);
		}

		bool RegisterStreamables()
		{
			using func_t = decltype(&NiExtraDataContainer::RegisterStreamables);
			REL::Relocation<func_t> func{ REL::Offset(0x1B96BD0) };  // RegisterStreamables function
			return func(this);
		}

		void LinkObject(std::uint32_t a_index)
		{
			using func_t = decltype(&NiExtraDataContainer::LinkObject);
			REL::Relocation<func_t> func{ REL::Offset(0x1B96C80) };  // LinkObject function
			return func(this, a_index);
		}

		void SaveBinary()
		{
			using func_t = decltype(&NiExtraDataContainer::SaveBinary);
			REL::Relocation<func_t> func{ REL::Offset(0x1B96D70) };  // SaveBinary function
			return func(this);
		}

		bool CheckLargeSize() const
		{
			using func_t = decltype(&NiExtraDataContainer::CheckLargeSize);
			REL::Relocation<func_t> func{ REL::Offset(0x1B96E80) };  // CheckLargeSize function
			return func(this);
		}

		// Конструкторы с адресами из дизассемблера
		// Constructor(uint) - 0x1CDAB0
		// Destructor - 0x1CDC10 
		// scalar_deleting_destructor - 0x1CDD00

		// members
		BSTArray<NiPointer<NiExtraData>, BSTArrayHeapAllocator> data;  // 00 - массив указателей на NiExtraData
		BSReadWriteLock lock;                                          // 18 - блокировка для потокобезопасности
	};
	static_assert(sizeof(NiExtraDataContainer) == 0x20);
}
