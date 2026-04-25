#pragma once

#include "REL/Relocation.h"
#include "REL/Version.h"

namespace RE
{
    namespace RTTI
    {
        // Version-aware RTTI IDs
        // Usage: inline constexpr auto IMemoryStoreBase = REL_ID_VER(vr_id, ae_id);

        // Example entries - you'll need to fill in actual IDs
        inline constexpr auto IMemoryStoreBase = REL_ID_VER(0, 0);  // Replace with actual IDs
        inline constexpr auto IMemoryStore = REL_ID_VER(0, 0);
        inline constexpr auto IMemoryHeap = REL_ID_VER(0, 0);
        inline constexpr auto ScrapHeap = REL_ID_VER(0, 0);

        // Keep existing non-versioned IDs for compatibility
        // These can be gradually migrated to version-aware format
        inline constexpr REL::ID AIProcess__PendingActorHeadData{ 892595 };
        inline constexpr REL::ID AStarSearchBase{ 640682 };
        // ... rest of existing IDs
    }
}
