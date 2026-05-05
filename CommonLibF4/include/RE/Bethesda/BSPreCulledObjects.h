#pragma once

#include "REL/IDSelection.h"
#include "RE/RTTI_IDs.h"
#include "RE/RTTI_IDs_AE.h"
#include "RE/VTABLE_IDs.h"
#include "RE/VTABLE_IDs_AE.h"

namespace RE
{
	class BSCullingGroup;
	class NiAVObject;

	struct BSPreCulledObjects
	{
	public:
		struct ObjectRecord
		{
		public:
			// members
			NiAVObject* obj{ nullptr };  // 00
			std::uint32_t flags{ 0 };    // 08
		};
		static_assert(sizeof(ObjectRecord) == 0x10);
		
		static void* Get3DForID(uint32_t id)
		{
			using func_t = decltype(&RE::BSPreCulledObjects::Get3DForID);
			REL::Relocation<func_t> func{ REL::SelectVersionID(1087700, 2317330) };
			return func(id);
		}
	
	};
	static_assert(std::is_empty_v<BSPreCulledObjects>);
}
