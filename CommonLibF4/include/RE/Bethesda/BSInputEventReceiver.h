#pragma once

#include "REL/IDSelection.h"
#include "RE/RTTI_IDs.h"
#include "RE/RTTI_IDs_AE.h"
#include "RE/VTABLE_IDs.h"
#include "RE/VTABLE_IDs_AE.h"

namespace RE
{
	class InputEvent;

	class __declspec(novtable) BSInputEventReceiver
	{
	public:
		static constexpr auto RTTI{ REL::SelectVersionID(RTTI::BSInputEventReceiver, RTTI_AE::BSInputEventReceiver) };
		static constexpr auto VTABLE{ VTABLE::BSInputEventReceiver };

		// add
		virtual void PerformInputProcessing(const InputEvent* a_queueHead) = 0;  // 00

		// members
		std::uint32_t currInputTimeCount;  // 08
	};
	static_assert(sizeof(BSInputEventReceiver) == 0x10);
}
