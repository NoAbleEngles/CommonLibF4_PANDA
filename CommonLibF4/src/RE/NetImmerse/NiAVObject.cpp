#include "C:/cpp/CommonLibF4/build/CommonLibF4/CMakeFiles/CommonLibF4.dir/Release/cmake_pch.hxx"
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

		// Если это NiNode, то обходим его дочерние объекты
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
