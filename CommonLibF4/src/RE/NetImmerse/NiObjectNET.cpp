#include "F4SE/Impl/PCH.h"
#include "RE/NetImmerse/NiObjectNET.h"

#include "RE/NetImmerse/NiTimeController.h"

namespace RE
{
	NiObjectNET::NiObjectNET() { stl::emplace_vtable(this); }

	NiObjectNET::~NiObjectNET() {}  // NOLINT(modernize-use-equals-default)
}

