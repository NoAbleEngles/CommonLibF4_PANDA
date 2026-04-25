#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/NetImmerse/NiObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/NetImmerse/NiExtraData.h"

namespace RE
{
	class NiTimeController;

	class __declspec(novtable) NiObjectNET :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiObjectNET };
		static constexpr auto VTABLE{ VTABLE::NiObjectNET };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiObjectNET };

		NiObjectNET();
		virtual ~NiObjectNET();  // NOLINT(modernize-use-override) 00

		F4_HEAP_REDEFINE_NEW(NiObjectNET);

		[[nodiscard]] std::string_view GetName() const { return name; }

		// members
		BSFixedString name{ "" };                 // 10
		NiPointer<NiTimeController> controllers;  // 18
		NiExtraDataContainer* extra{ nullptr };   // 20

		bool AddExtraData(NiExtraData* extraData) {
			using func_t = decltype(&NiObjectNET::AddExtraData);
			REL::Relocation<func_t> func{ REL::Offset(0x1B978C0) };
			return func(this, extraData);
		}

		NiExtraData* GetExtraData(const BSFixedString& strName) {
			using func_t = decltype(&NiObjectNET::GetExtraData);
			REL::Relocation<func_t> func{ REL::Offset(0x1B97A10) };
			return func(this, strName);
		}

		bool HasExtraData(const BSFixedString& strName) {
			return GetExtraData(strName) != nullptr;
		}
	};
	static_assert(sizeof(NiObjectNET) == 0x28);
}
