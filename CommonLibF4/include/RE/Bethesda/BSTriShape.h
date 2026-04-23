#pragma once

#include "RE/NetImmerse/NiAVObject.h"

namespace RE
{
	class BSGeometry;  // Forward declaration - would need to be implemented
	class BSTriShapeBuffer;
	class NiCloningProcess;

	class __declspec(novtable) BSTriShape :
		public NiAVObject  // 000 - simplified, should inherit from BSGeometry when available
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTriShape };
		static constexpr auto VTABLE{ VTABLE::BSTriShape };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTriShape };

		virtual ~BSTriShape();

		F4_HEAP_REDEFINE_ALIGNED_NEW(BSTriShape);

		// members - basic triangle shape data - base is 0x120
		void* vertexBuffer;                              // 120 - vertex buffer data
		void* indexBuffer;                               // 128 - index buffer data  
		std::uint32_t vertexCount;                       // 130 - number of vertices
		std::uint32_t triangleCount;                     // 134 - number of triangles
		std::uint16_t vertexStride;                      // 138 - bytes per vertex
		std::uint16_t pad13A;                            // 13A
		std::uint32_t bufferFlags;                       // 13C - buffer state flags
		void* extraData;                                 // 140 - additional geometry data
		std::uint64_t pad148;                            // 148 - padding
	};
	static_assert(sizeof(BSTriShape) == 0x150);
}
