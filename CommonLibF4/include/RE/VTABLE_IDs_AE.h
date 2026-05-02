#pragma once

#include "REL/Relocation.h"

namespace RE
{
    namespace VTABLE_AE
    {
        // AE (Anniversary Edition / Next-Gen) VTABLE IDs
        // OG IDs remain in VTABLE_IDs.h
        // Usage in classes: static constexpr auto VTABLE{ REL::REL_ID_VER(VTABLE::ClassName, VTABLE_AE::ClassName) };

        // Memory Management
        inline constexpr std::array<REL::ID, 1> IMemoryStoreBase{ REL::ID(4858639) };
        inline constexpr std::array<REL::ID, 1> IMemoryStore{ REL::ID(4858637) };
        inline constexpr std::array<REL::ID, 1> IMemoryHeap{ REL::ID(4858649) };
        inline constexpr std::array<REL::ID, 1> ScrapHeap{ REL::ID(4858641) };

		// Actor
		inline constexpr std::array<REL::ID, 1> ActorPackageData{ REL::ID(1373528) };
		inline constexpr std::array<REL::ID, 1> EquippedItemData{ REL::ID(1373528) };
		inline constexpr std::array<REL::ID, 1> EquippedWeaponData{ REL::ID(1527616) };
		inline constexpr std::array<REL::ID, 1> MagicTarget{ REL::ID(343092) };
		inline constexpr std::array<REL::ID, 1> ActorState{ REL::ID(614888) };
		inline constexpr std::array<REL::ID, 1> IPostAnimationChannelUpdateFunctor{ REL::ID(671437) };
        // Add more AE-specific VTABLE IDs here as needed
    }
}
