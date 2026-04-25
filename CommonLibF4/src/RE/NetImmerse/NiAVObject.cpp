#include "F4SE/Impl/PCH.h"
#include "RE/NetImmerse/NiAVObject.h"

#include "RE/NetImmerse/NiCollisionObject.h"
#include "RE/NetImmerse/NiNode.h"

namespace RE
{
	NiAVObject::NiAVObject()
	{
		stl::emplace_vtable(this);
		local.MakeIdentity();
		world.MakeIdentity();
		previousWorld.MakeIdentity();
		flags.flags = 0xE;
	}

	NiAVObject::~NiAVObject() {}  // NOLINT(modernize-use-equals-default)

	bool NiAVObject::Visit(const std::function<bool(NiAVObject*)>& functor)
	{
		if (!functor(this)) {
			return false;
		}

		// Р•СЃР»Рё СЌС‚Рѕ NiNode, С‚Рѕ РѕР±С…РѕРґРёРј РµРіРѕ РґРѕС‡РµСЂРЅРёРµ РѕР±СЉРµРєС‚С‹
		if (auto node = IsNode()) {
			for (std::uint16_t i = 0; i < node->children.size(); ++i) {
				auto& child = node->children[i];
				if (child && !child->Visit(functor)) {
					return false;
				}
			}
		}

		return true;
	}
}

