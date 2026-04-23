#include "C:/cpp/CommonLibF4/build/CommonLibF4/CMakeFiles/CommonLibF4.dir/Release/cmake_pch.hxx"
#include "RE/Bethesda/Actor.h"

#include "RE/Bethesda/TESBoundAnimObjects.h"
#include "RE/Bethesda/TESBoundObjects.h"

namespace RE
{
	TESNPC* Actor::GetNPC() const noexcept
	{
		const auto objRef = GetObjectReference();
		assert(objRef->GetFormType() == ENUM_FORM_ID::kNPC_);
		return static_cast<TESNPC*>(objRef);
	}
}
