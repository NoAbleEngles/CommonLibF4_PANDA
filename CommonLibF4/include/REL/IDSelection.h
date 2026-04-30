#pragma once

#include "REL/Relocation.h"
#include "REL/Version.h"

namespace REL
{
    // Constexpr helper to select between OG and AE IDs at compile time
    constexpr ID SelectVersionID(std::uint64_t a_ogID, std::uint64_t a_aeID) noexcept
    {
        if constexpr (GAME_VERSION == GameVersion::AE) {
            return ID(a_aeID);
        } else {
            return ID(a_ogID);
        }
    }

	constexpr ID SelectVersionID(const ID& a_ogID, const ID& a_aeID) noexcept
	{
		if constexpr (GAME_VERSION == GameVersion::AE) {
			return a_aeID;
		} else {
			return a_ogID;
		}
	}

	// Constexpr helper for VTABLE arrays
	constexpr std::array<ID, 1> SelectVersionVTABLE(std::uint64_t a_ogID, std::uint64_t a_aeID) noexcept
	{
		return { SelectVersionID(a_ogID, a_aeID) };
	}

	template<std::size_t N>
	constexpr std::array<ID, N> SelectVersionVTABLE(const std::array<ID, N>& a_ogVTABLE, const std::array<ID, N>& a_aeVTABLE) noexcept
	{
		if constexpr (GAME_VERSION == GameVersion::AE) {
			return a_aeVTABLE;
		} else {
			return a_ogVTABLE;
		}
	}
}
