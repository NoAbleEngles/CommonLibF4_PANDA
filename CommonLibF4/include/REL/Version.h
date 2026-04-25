#pragma once

#include <cstdint>

namespace REL
{
    // Forward declaration
    class ID;

    // Game version type
    enum class GameVersion
    {
        VR,  // Virtual Reality version
        AE   // Anniversary Edition / Standard version
    };

    // Compile-time game version selection
    // Define F4_GAME_VERSION_VR or F4_GAME_VERSION_AE in your project settings
#if defined(F4_GAME_VERSION_VR)
    inline constexpr GameVersion GAME_VERSION = GameVersion::VR;
#elif defined(F4_GAME_VERSION_AE)
    inline constexpr GameVersion GAME_VERSION = GameVersion::AE;
#else
    // Default to AE if nothing specified
    inline constexpr GameVersion GAME_VERSION = GameVersion::AE;
#endif

    // Version-aware ID wrapper
    // This allows compile-time selection of different IDs for different game versions
    // Example: inline constexpr auto MyID = REL_ID_VER(123456, 789012);
    template <std::uint64_t VR_ID, std::uint64_t AE_ID>
    struct VersionID
    {
        static constexpr std::uint64_t get() noexcept
        {
            if constexpr (GAME_VERSION == GameVersion::VR) {
                return VR_ID;
            } else {
                return AE_ID;
            }
        }

        constexpr operator std::uint64_t() const noexcept
        {
            return get();
        }

        constexpr operator ID() const noexcept
        {
            return ID(get());
        }
    };

    // Helper macro for defining version-aware IDs
    // Usage: inline constexpr auto MyID = REL_ID_VER(vr_id, ae_id);
#define REL_ID_VER(vr_id, ae_id) REL::VersionID<vr_id, ae_id>{}
}
