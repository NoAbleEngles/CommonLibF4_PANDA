#pragma once

#include "REL/IDSelection.h"
#include "RE/RTTI_IDs.h"
#include "RE/RTTI_IDs_AE.h"
#include "RE/VTABLE_IDs.h"
#include "RE/VTABLE_IDs_AE.h"

namespace RE::BSSystemFileStreamer
{
	inline void UncacheAll(bool a_block)
	{
		using func_t = decltype(&UncacheAll);
		REL::Relocation<func_t> func{ REL::SelectVersionID(40925, 2268797) };
		return func(a_block);
	}
}
