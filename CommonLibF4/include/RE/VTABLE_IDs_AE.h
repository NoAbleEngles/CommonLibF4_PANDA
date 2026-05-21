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

		//FavoritesManager
		inline constexpr std::array<REL::ID, 4> FavoritesManager{ REL::ID(453195), REL::ID(892289), REL::ID(4826565), REL::ID(4826566) };

		//FormComponents
		inline constexpr std::array<REL::ID, 1> BSIMusicType{ REL::ID(4826566) };

		//GameScript
		inline constexpr std::array<REL::ID, 62> GameScript__BasicEventHandler{ 
			REL::ID(672533),	//1
			REL::ID(1330213),	//2
			REL::ID(4826663),	//3
			REL::ID(4826664),	//4
			REL::ID(4826665),	//5
			REL::ID(4826666),	//6
			REL::ID(4826667),	//7
			REL::ID(4826668),	//8
			REL::ID(4826669),	//9
			REL::ID(4826670),  //10
			REL::ID(4826671),  //11
			REL::ID(4826672),  //12
			REL::ID(4826673),  //13
			REL::ID(4826674),  //14
			REL::ID(4826675),  //15
			REL::ID(4826676),  //16
			REL::ID(4826677),  //17
			REL::ID(4826678),  //18
			REL::ID(4826679),  //19
			REL::ID(4826680),  //20
			REL::ID(4826681),  //21
			REL::ID(4826682),  //22
			REL::ID(4826683),  //23
			REL::ID(4826684),  //24
			REL::ID(4826685),  //25
			REL::ID(4826686),  //26
			REL::ID(4826687),  //27
			REL::ID(4826688),  //28
			REL::ID(4826689),  //29
			REL::ID(4826690),  //30
			REL::ID(4826691),  //31
			REL::ID(4826692),  //32
			REL::ID(4826693),  //33
			REL::ID(4826694),  //34
			REL::ID(4826695),  //35
			REL::ID(4826696),  //36
			REL::ID(4826697),  //37
			REL::ID(4826698),  //38
			REL::ID(4826699),  //39
			REL::ID(4826700),  //40
			REL::ID(4826701),  //41
			REL::ID(4826702),  //42
			REL::ID(4826703),  //43
			REL::ID(4826704),  //44
			REL::ID(4826705),  //45
			REL::ID(4826706),  //46
			REL::ID(4826707),  //47
			REL::ID(4826708),  //48
			REL::ID(4826709),  //49
			REL::ID(4826710),  //50
			REL::ID(4826711),  //51
			REL::ID(4826712),  //52
			REL::ID(4826713),  //53
			REL::ID(4826714),  //54
			REL::ID(4826715),  //55
			REL::ID(4826716),  //56
			REL::ID(4826717),  //57
			REL::ID(4826718),  //58
			REL::ID(4826719),  //59
			REL::ID(4826720),  //60
			REL::ID(4826721),  //61
			REL::ID(4826722)   //62
		};

		inline constexpr std::array<REL::ID, 3> GameScript__CombatEventHandler
		{
			REL::ID(226990),
			REL::ID(4826601),
			REL::ID(4826602)
		};
    }
}
