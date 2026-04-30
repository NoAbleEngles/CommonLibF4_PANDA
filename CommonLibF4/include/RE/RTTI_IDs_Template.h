#pragma once

#include "REL/Relocation.h"
#include "REL/Version.h"

// ============================================================================
// TEMPLATE FOR VERSION-AWARE RTTI IDs
// ============================================================================
// 
// This file contains RTTI IDs that differ between Fallout 4 versions.
// 
// HOW TO USE:
// 1. Find the RTTI ID in both OG and AE versions
// 2. Add entry: inline constexpr auto ClassName = REL_ID_VER(og_id, ae_id);
// 3. Comment the source of IDs for future reference
//
// SOURCES:
// - OG:  Fallout 4 Original (Pre-AE) version 1.10.163 or earlier
// - AE:  Fallout 4 Anniversary Edition / Next-Gen version 1.10.980+
//
// ============================================================================

namespace RE
{
    namespace RTTI
    {
        // ====================================================================
        // MEMORY MANAGEMENT
        // ====================================================================

        // Source: RTTI dump OG 1.10.163 / AE 1.10.980
        inline constexpr auto IMemoryStoreBase = REL_ID_VER(0, 0);  // TODO: Find actual IDs
        inline constexpr auto IMemoryStore = REL_ID_VER(0, 0);
        inline constexpr auto IMemoryHeap = REL_ID_VER(0, 0);
        inline constexpr auto ScrapHeap = REL_ID_VER(0, 0);
        inline constexpr auto MemoryManager = REL_ID_VER(0, 0);

        // ====================================================================
        // FORMS (TESForm hierarchy)
        // ====================================================================

        // Source: RTTI dump OG 1.10.163 / AE 1.10.980
        inline constexpr auto TESForm = REL_ID_VER(0, 0);
        inline constexpr auto TESObjectREFR = REL_ID_VER(0, 0);
        inline constexpr auto Actor = REL_ID_VER(0, 0);
        inline constexpr auto PlayerCharacter = REL_ID_VER(0, 0);

        // ====================================================================
        // BSScript (Papyrus)
        // ====================================================================

        // Source: RTTI dump OG 1.10.163 / AE 1.10.980
        inline constexpr auto BSScript__IVirtualMachine = REL_ID_VER(0, 0);
        inline constexpr auto BSScript__Stack = REL_ID_VER(0, 0);

        // ====================================================================
        // NI (NetImmerse/Gamebryo)
        // ====================================================================

        // Source: RTTI dump OG 1.10.163 / AE 1.10.980
        inline constexpr auto NiObject = REL_ID_VER(0, 0);
        inline constexpr auto NiAVObject = REL_ID_VER(0, 0);
        inline constexpr auto NiNode = REL_ID_VER(0, 0);
        inline constexpr auto BSGeometry = REL_ID_VER(0, 0);

        // ====================================================================
        // ADD YOUR CLASSES HERE
        // ====================================================================

        // Example format:
        // // Source: [where you found the IDs]
        // inline constexpr auto YourClassName = REL_ID_VER(og_id, ae_id);

    }  // namespace RTTI
}  // namespace RE
