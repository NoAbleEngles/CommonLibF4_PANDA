#pragma once

#include "REL/Version.h"
#include <string_view>

namespace REL
{
    // Compile-time version information
    struct VersionInfo
    {
        static constexpr std::string_view GetVersionName() noexcept
        {
            if constexpr (GAME_VERSION == GameVersion::VR) {
                return "Fallout 4 VR";
            } else {
                return "Fallout 4 AE/Standard";
            }
        }

        static constexpr std::string_view GetVersionShort() noexcept
        {
            if constexpr (GAME_VERSION == GameVersion::VR) {
                return "VR";
            } else {
                return "AE";
            }
        }

        static constexpr bool IsVR() noexcept
        {
            return GAME_VERSION == GameVersion::VR;
        }

        static constexpr bool IsAE() noexcept
        {
            return GAME_VERSION == GameVersion::AE;
        }

        // Get the selected ID from a version-aware ID
        template <std::uint64_t VR_ID, std::uint64_t AE_ID>
        static constexpr std::uint64_t GetSelectedID() noexcept
        {
            return VersionID<VR_ID, AE_ID>::get();
        }

        // Check if an ID is defined (non-zero)
        template <std::uint64_t VR_ID, std::uint64_t AE_ID>
        static constexpr bool IsIDDefined() noexcept
        {
            return GetSelectedID<VR_ID, AE_ID>() != 0;
        }
    };

    // Compile-time assertions for version checking
#define REQUIRE_VR() static_assert(REL::VersionInfo::IsVR(), "This code requires VR version")
#define REQUIRE_AE() static_assert(REL::VersionInfo::IsAE(), "This code requires AE version")
#define REQUIRE_ID_DEFINED(id) static_assert(REL::VersionInfo::IsIDDefined<id>(), "ID not defined for this version")
}
