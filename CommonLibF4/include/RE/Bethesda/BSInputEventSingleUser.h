#pragma once

#include "RE/Bethesda/BSInputEventReceiver.h"
#include "RE/Bethesda/BSInputEventUser.h"

#include "REL/IDSelection.h"
#include "RE/RTTI_IDs.h"
#include "RE/RTTI_IDs_AE.h"
#include "RE/VTABLE_IDs.h"
#include "RE/VTABLE_IDs_AE.h"

namespace RE
{
	class BSInputEventSingleUser :
		public BSInputEventReceiver,  // 00
		public BSInputEventUser       // 10
	{
	public:
		static constexpr auto RTTI{ REL::SelectVersionID(RTTI::BSInputEventSingleUser, RTTI_AE::BSInputEventSingleUser) };
		static constexpr auto VTABLE{ VTABLE::BSInputEventSingleUser };
	};
	static_assert(sizeof(BSInputEventSingleUser) == 0x20);
}
