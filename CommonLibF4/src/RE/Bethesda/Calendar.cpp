#include "C:/cpp/CommonLibF4/build/CommonLibF4/CMakeFiles/CommonLibF4.dir/Release/cmake_pch.hxx"
#include "RE/Bethesda/Calendar.h"

#include "RE/Bethesda/TESForms.h"

namespace RE
{
	float Calendar::GetHoursPassed() const noexcept
	{
		const auto days = gameDaysPassed ? gameDaysPassed->GetValue() : 1.0F;
		return days * 24.0F;
	}
}
