#pragma once

#include "RE/Bethesda/BSTSingleton.h"

#include "REL/IDSelection.h"
#include "RE/RTTI_IDs.h"
#include "RE/RTTI_IDs_AE.h"
#include "RE/VTABLE_IDs.h"
#include "RE/VTABLE_IDs_AE.h"

namespace RE
{
	class TESGlobal;

	class Calendar :
		public BSTSingletonSDM<Calendar>
	{
	public:
		[[nodiscard]] static Calendar* GetSingleton()
		{
			REL::Relocation<Calendar**> singleton{ REL::SelectVersionID(1444952, 4796378) };
			return *singleton;
		}

		[[nodiscard]] float GetHoursPassed() const noexcept;

		// members
		TESGlobal* gameYear;            // 08
		TESGlobal* gameMonth;           // 10
		TESGlobal* gameDay;             // 18
		TESGlobal* gameHour;            // 20
		TESGlobal* gameDaysPassed;      // 28
		TESGlobal* timeScale;           // 30
		std::uint32_t midnightsPassed;  // 38
		float rawDaysPassed;            // 3C
	};
	static_assert(sizeof(Calendar) == 0x40);
}
