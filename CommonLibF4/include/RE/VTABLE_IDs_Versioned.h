#pragma once

#include "REL/Relocation.h"
#include "REL/Version.h"

namespace RE
{
	namespace VTABLE
	{
		// Version-aware VTABLE IDs
		// Usage: inline constexpr auto IMemoryStoreBase = REL_ID_VER(og_id, ae_id);
		// First parameter: OG (Original/Pre-AE) ID
		// Second parameter: AE (Anniversary Edition/Next-Gen) ID

		// Memory Management
		inline constexpr auto IMemoryStoreBase = REL_ID_VER(0, 483627);   // OG ID needed
		inline constexpr auto IMemoryStore = REL_ID_VER(0, 217723);       // OG ID needed
		inline constexpr auto IMemoryHeap = REL_ID_VER(0, 1216172);       // OG ID needed
		inline constexpr auto ScrapHeap = REL_ID_VER(0, 1084382);         // OG ID needed

		// Add more version-aware VTABLE IDs here
		// Format: inline constexpr auto ClassName = REL_ID_VER(og_id, ae_id);
	}
}
