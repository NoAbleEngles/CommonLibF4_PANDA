#pragma once

#include "RE/NetImmerse/NiObject.h"

#include "REL/IDSelection.h"
#include "RE/RTTI_IDs.h"
#include "RE/RTTI_IDs_AE.h"
#include "RE/VTABLE_IDs.h"
#include "RE/VTABLE_IDs_AE.h"

namespace RE
{
	struct hknpWorldCinfo;

	class bhkWorld :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ REL::SelectVersionID(RTTI::bhkWorld, RTTI_AE::bhkWorld) };
		static constexpr auto VTABLE{ VTABLE::bhkWorld };
		static constexpr auto Ni_RTTI{ REL::SelectVersionID(Ni_RTTI::bhkWorld, Ni_RTTI_AE::bhkWorld) };

		// add
		virtual bool Update(std::uint32_t a_updateFlags);  // 28
		virtual void Init(const hknpWorldCinfo& a_info);   // 29

		static bool RemoveObjects(NiAVObject* a_object, bool a_recurse, bool a_force)
		{
			using func_t = decltype(&RemoveObjects);
			REL::Relocation<func_t> func{ REL::SelectVersionID(1514984, 2277721) };
			return func(a_object, a_recurse, a_force);
		}

		// members
		std::byte pad[0x180 - 0x10];  // 0x10 - TODO
	};
	static_assert(sizeof(bhkWorld) == 0x180);
}
