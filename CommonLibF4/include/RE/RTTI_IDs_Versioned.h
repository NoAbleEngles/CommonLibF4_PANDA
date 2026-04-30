#pragma once

#include "REL/Relocation.h"
#include "REL/Version.h"

namespace RE
{
	namespace RTTI
	{
		// Version-aware RTTI IDs
		// Usage: inline constexpr auto IMemoryStoreBase = REL_ID_VER(og_id, ae_id);
		// First parameter: OG (Original/Pre-AE) ID
		// Second parameter: AE (Anniversary Edition/Next-Gen) ID

		// Memory Management
		inline constexpr auto IMemoryStoreBase = REL_ID_VER(0, 4858639);  // OG ID needed
		inline constexpr auto IMemoryStore = REL_ID_VER(0, 4858637);      // OG ID needed
		inline constexpr auto IMemoryHeap = REL_ID_VER(0, 4858649);       // OG ID needed
		inline constexpr auto ScrapHeap = REL_ID_VER(0, 4858641);         // OG ID needed

		// Add more version-aware RTTI IDs here
		// Format: inline constexpr auto ClassName = REL_ID_VER(og_id, ae_id);
	}
}
