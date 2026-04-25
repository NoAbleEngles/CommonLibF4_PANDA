#pragma once

#include "REL/Relocation.h"
#include "REL/Version.h"

namespace RE
{
    namespace VTABLE
    {
        // Version-aware VTABLE IDs
        // Usage: inline constexpr auto IMemoryStoreBase = REL_ID_VER(vr_id, ae_id);

        // Example entries - you'll need to fill in actual IDs
        inline constexpr auto IMemoryStoreBase = REL_ID_VER(0, 0);  // Replace with actual IDs
        inline constexpr auto IMemoryStore = REL_ID_VER(0, 0);
        inline constexpr auto IMemoryHeap = REL_ID_VER(0, 0);
        inline constexpr auto ScrapHeap = REL_ID_VER(0, 0);

        // Keep existing non-versioned IDs for compatibility
    }
}
