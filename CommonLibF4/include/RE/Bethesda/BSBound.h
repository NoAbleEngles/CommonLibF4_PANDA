#pragma once

#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTObjectArena.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/NetImmerse/NiAVObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/NetImmerse/NiExtraData.h"
#include "RE/NetImmerse/NiPoint3.h"
#include "RE/NetImmerse/NiTransform.h"
#include "REL/Relocation.h"

namespace RE
{
	class __declspec(novtable) BSBound :
		public NiExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSBound };
		static constexpr auto VTABLE{ VTABLE::BSBound };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSBound };

		// NiExtraData overrides
		virtual NiExtraData* CreateClone() override { return nullptr; }  // 26

		// members
		NiPoint3 center;   // 18
		NiPoint3 extents;  // 24
	};
	static_assert(sizeof(BSBound) == 0x30);

	// fwd decls for cloth/havok types we reference in signatures
	struct hkQsTransformf;
	class hclBSWorld;
	class hclClothInstance;
	struct hkBitField;
	class hkaSkeleton;
	class NiNode;

	class __declspec(novtable) BSClothExtraData :
		public NiExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSClothExtraData };
		static constexpr auto VTABLE{ VTABLE::BSClothExtraData };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSClothExtraData };

		// construction
		static BSClothExtraData* CreateObject()
		{
			using func_t = decltype(&BSClothExtraData::CreateObject);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DA6240 };
			return func();
		}

		// NiObject overrides
		virtual NiObject* CreateClone([[maybe_unused]] NiCloningProcess& a_cloneData) override { return nullptr; };  // 1A
		virtual void LoadBinary([[maybe_unused]] NiStream& a_stream) override {};                                    // 1B
		virtual void SaveBinary([[maybe_unused]] NiStream& a_stream) override {};                                    // 1E

		// BSClothExtraData API (from bin/xrefs)
		void CopyMembers(NiCloningProcess& a_cloneData)
		{
			using func_t = decltype(&BSClothExtraData::CopyMembers);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DA6390 };
			return func(this, a_cloneData);
		}

		void CreateInstance(NiAVObject& a_root, NiTransform& a_local, NiAVObject* a_target)
		{
			using func_t = decltype(&BSClothExtraData::CreateInstance);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DA6890 };
			return func(this, a_root, a_local, a_target);
		}

		void ReleaseInstances()
		{
			using func_t = decltype(&BSClothExtraData::ReleaseInstances);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DA6C00 };
			return func(this);
		}

		void SetWorld(hclBSWorld* a_world)
		{
			using func_t = decltype(&BSClothExtraData::SetWorld);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DA6C30 };
			return func(this, a_world);
		}

		bool HasWorld() const
		{
			using func_t = decltype(&BSClothExtraData::HasWorld);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DA6E10 };
			return func(this);
		}

		void Teleport(hkQsTransformf& a_worldXform)
		{
			using func_t = decltype(&BSClothExtraData::Teleport);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DA6E20 };
			return func(this, a_worldXform);
		}

		void TeleportToMatchBoneTransform(BSFixedString& a_boneName)
		{
			using func_t = decltype(&BSClothExtraData::TeleportToMatchBoneTransform);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DA6EB0 };
			return func(this, a_boneName);
		}

		void ScaleSkinBones(BSTHashMap<BSFixedString, NiPoint3>& a_scaleByBoneName)
		{
			using func_t = decltype(&BSClothExtraData::ScaleSkinBones);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DA7920 };
			return func(this, a_scaleByBoneName);
		}

		void* GetTimingData()
		{
			using func_t = decltype(&BSClothExtraData::GetTimingData);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DA7980 };
			return func(this);
		}

		void SetTargetLODLevel(uint32_t a_level)
		{
			using func_t = void (*)(BSClothExtraData*, uint32_t);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DA79F0 };
			return func(this, a_level);
		}

		void SetSettleOnTransitionToSim(bool a_enable)
		{
			using func_t = decltype(&BSClothExtraData::SetSettleOnTransitionToSim);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DA7A40 };
			return func(this, a_enable);
		}

		void GatherDeformationBones(BSTObjectArena<NiAVObject>& a_outBones)
		{
			using func_t = decltype(&BSClothExtraData::GatherDeformationBones);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DA7A90 };
			return func(this, a_outBones);
		}

		// quick view into cloth instances used by hooks (observed at +0x60 and +0x70)
		// 60 - instances data pointer, 68 - instances capacity, 70 - instances size
		std::byte _pad18[0x48];  // 18 .. 5F - engine-owned fields/arrays (ctor touches 3C, 44, 48, 58)
		BSTArray<void*> instances;  // 60

		F4_HEAP_REDEFINE_NEW(BSClothExtraData);
	};
	static_assert(offsetof(BSClothExtraData, instances) == 0x60);

	// Forward declarations for hkaSkeleton-related types
	class hkaSkeleton;
	template<typename T, typename Allocator> class hkArray;

	// BSClothUtils is a namespace in the shipping binary. Provide thin wrappers
	// that call into the game using base + RVA (base observed at 0x7FF6633D0000).
	namespace BSClothUtils
	{
		// Some enums observed in signatures (exact values game-defined)
		enum class LODLevel : uint32_t
		{
			// unknown concrete values in different builds; use as passthrough
		};

		// Create and attach BSClothExtraData for a 3D object, clone template extra if present
		inline BSClothExtraData* CreateClothFor3d(NiAVObject& a_root, const char* a_extraName, NiTransform& a_local, NiAVObject* a_target)
		{
			using func_t = BSClothExtraData* (*)(NiAVObject&, const char*, NiTransform&, NiAVObject*);
			// 0x7FF66517AE30 - 0x7FF6633D0000 = 0x1DAAE30
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DAAE30 };
			return func(a_root, a_extraName, a_local, a_target);
		}

		// Cache current NiAVObject name into NiStringExtraData("BSClothCurrentName") and attach
		inline NiExtraData* CacheCurrentAVObjectName(NiAVObject& a_obj)
		{
			using func_t = NiExtraData* (*)(NiAVObject&);
			// 0x7FF66517AF00 - 0x7FF6633D0000 = 0x1DAAF00
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DAAF00 };
			return func(a_obj);
		}

		// Remove cloth data from world for all AVObjects under given root. Returns true if removed
		inline bool RemoveClothFromWorld(NiAVObject& a_root)
		{
			using func_t = bool (*)(NiAVObject&);
			// 0x7FF66517AF90 - 0x7FF6633D0000 = 0x1DAAF90
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DAAF90 };
			return func(a_root);
		}

		// Teleport cloth instance and all deformation bones
		inline void Teleport(hclClothInstance& a_instance,
			const hkQsTransformf& a_fromWorld,
			const hkQsTransformf& a_toWorld,
			hkBitField* a_mask,
			hkQsTransformf* a_outWorld = nullptr)
		{
			using func_t = void (*)(hclClothInstance&, const hkQsTransformf&, const hkQsTransformf&, hkBitField*, hkQsTransformf*);
			// 0x7FF66517AFC0 - 0x7FF6633D0000 = 0x1DAAFC0
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DAAFC0 };
			return func(a_instance, a_fromWorld, a_toWorld, a_mask, a_outWorld);
		}

		// Scale skin bones by name => scale vector mapping
		inline void ScaleSkinBones(hclClothInstance& a_instance, BSTHashMap<BSFixedString, NiPoint3>& a_scaleByBoneName)
		{
			using func_t = void (*)(hclClothInstance&, BSTHashMap<BSFixedString, NiPoint3>&);
			// 0x7FF66517B060 - 0x7FF6633D0000 = 0x1DAB060
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DAB060 };
			return func(a_instance, a_scaleByBoneName);
		}

		// Transform-set driving a single cloth instance
		class __declspec(novtable) BSTransformSet
		{
		public:
			static constexpr auto RTTI{ RTTI::BSClothUtils__BSTransformSet };
			static constexpr auto VTABLE{ VTABLE::BSClothUtils__BSTransformSet };

			virtual ~BSTransformSet() = default;  // 00
			// Base chain: hclTransformSet -> hkReferencedObject -> hkBaseObject
			// Note: gameplay-specific helpers below are non-virtual utility thunks in the binary

		// layout helpers (reverse engineered from ctor/dtor)
			struct SmallArray
			{
				void* data;             // +00
				std::uint32_t size;     // +08
				std::uint32_t capacity; // +0C (0x80000000 sentinel when empty)
			};

			// members (offsets from this, after the hclTransformSet base)
			std::byte _pad00[0x28];   // 00 - 27 (vptr + hclTransformSet base fields)
			
			// +30: hkaSkeleton* (reference counted)
			void* hkaSkeleton;        // 30 - hkaSkeleton* (AddRef in ctor at 141DAB8D4+)
			void* hkRefB;             // 38 - secondary hk ref object
			
			// +40: hkArray-style storage for bone transforms (modelPose)
			SmallArray arr40;         // 40/48/4C - hkQsTransformf[] storage
			std::uint32_t _pad50;     // 50 - padding
			std::uint32_t _pad54;     // 54
			SmallArray arr58;         // 58/60/64 - hkBitField storage
			std::uint32_t _pad68;     // 68
			std::uint32_t _pad6C;     // 6C
			SmallArray arr70;         // 70/78/7C - hkBitField storage
			std::uint32_t _pad80;     // 80
			std::uint32_t _pad84;     // 84

			// +88: BSTArray<NiPointer<NiAVObject>> - deformation bones (ctor at 141DAB946+)
			BSTArray<NiPointer<NiAVObject>> deformAVObjects;  // 88
			std::uint32_t _pad9C;                             // 9C - 9F
			
			// +A0-CF: Internal engine arrays/allocators
			std::byte _padA0_to_D0[0x30];                     // A0 - CF
			
			// +D0: BSTArray<NiPointer<NiNode>> (ctor at 141DAB995+)
			BSTArray<NiPointer<NiNode>> deformNodes;          // D0
			std::uint32_t _padE4;                             // E4 - E7
			
			// +E8-FF: More internal arrays (ctor at 141DAB9BD+)
			std::byte _padE8_to_100[0x18];                    // E8 - FF

			// +100-13C: Four SmallArray structures (modelPose-related)
			SmallArray arr100;        // 100/108/10C - allocated at ctor 141DAB9E2+
			SmallArray arr110;        // 110/118/11C
			SmallArray arr120;        // 120/128/12C
			SmallArray arr130;        // 130/138/13C

			// +140-16C: hkQsTransformf - previous frame transform (root)
			NiPoint3 prevTranslation; // 140 - used in notifyBeginAccess (141DADC24+)
			std::uint32_t _pad14C;    // 14C
			NiPoint3 prevRotation;    // 150 - hkQuaternionf (4 floats, last is W)
			std::uint32_t _pad15C;    // 15C
			NiPoint3 prevScale;       // 160 - scale vector
			std::uint32_t _pad16C;    // 16C

			// +170-17C: NiPoint3 - base offset/scale (init at 141DABA6F+)
			float offsetX;            // 170 - init to dword_145C08DA0
			float offsetY;            // 174 - init to dword_145C08DA4
			float offsetZ;            // 178 - init to dword_145C08DA8
			std::uint32_t _pad17C;    // 17C

			// +180: hclClothInstance* pointer (set at 141DABAA2)
			void* clothInstance;      // 180 - hclClothInstance*
			
			// +188-1B7: Runtime state and LOD fields
			std::int32_t rootBoneIndex;   // 188 - root bone index (-1 = none)
			std::int32_t frameCounter;    // 18C - BeginFrame counter (init at 141DABAD1)
			std::int32_t accessCounter;   // 190 - notifyBeginAccess increment (init 0)
			std::int32_t field194;        // 194 - set to 1 in ctor (141DABADC)
			
			std::int32_t animateStateIdx; // 198 - "Animate" state index (-1 initially, from 141DABAF2)
			std::int32_t simulateStateIdx;// 19C - "Simulate" state index (-1 initially)
			std::int32_t field1A0;        // 1A0 - init to -1 (141DABAF2)
			
			void* field1A4;               // 1A4 - pointer field
			float field1AC;               // 1AC - float parameter
			void* field1B0;               // 1B0 - pointer field
			
			std::uint32_t stateFlags;     // 1B4 - init to 0x101 (141DABAFD)
			                              // Low byte: prediction reset flag
			                              // High byte: state flags


			// Teleport a transform set (game-provided implementation)
			void Teleport(const hkQsTransformf& a_worldXform, hkBitField* a_mask)
			{
				using func_t = void (*)(BSTransformSet*, const hkQsTransformf&, hkBitField*);
				// RVA from shipping binary (FO4 1.10.163); free function taking this*
				REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DAB6E0 };
				return func(this, a_worldXform, a_mask);
			}

			// Gather deformation bones into arena (game-provided implementation)
			void GatherDeformationBones(BSTObjectArena<NiAVObject>& a_outBones)
			{
				using func_t = void (*)(BSTransformSet*, BSTObjectArena<NiAVObject>&);
				REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DAB740 };
				return func(this, a_outBones);
			}

			// Scale skin bones using a mask (game-provided implementation)
			void ScaleSkinBones(BSTHashMap<BSFixedString, NiPoint3>& a_scaleByBoneName, const hkBitField& a_mask)
			{
				using func_t = void (*)(BSTransformSet*, BSTHashMap<BSFixedString, NiPoint3>&, const hkBitField&);
				REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1DAB7A0 };
				return func(this, a_scaleByBoneName, a_mask);
			}

			// Returns whether cloth supports LOD switching (non-virtual)
			bool QClothSupportsLOD() const
			{
				using func_t = bool (*)(const BSTransformSet*);
				// RVA 0x1C3F3B0 from disassembly
				REL::Relocation<func_t> func{ REL::Module::get().base() + 0x1C3F3B0 };
				return func(this);
			}
		};

		// GPU buffer helper used during instantiation
		class __declspec(novtable) BSTriShapeBuffer
		{
		public:
			static constexpr auto RTTI{ RTTI::BSClothUtils__BSTriShapeBuffer };
			static constexpr auto VTABLE{ VTABLE::BSClothUtils__BSTriShapeBuffer };

			virtual ~BSTriShapeBuffer() = default;  // 00
			// Inherits: hclBuffer -> hkReferencedObject -> hkBaseObject

			// members (observed releases in dtor)
			std::byte _pad00[0x108];  // account for vptr so hkRefA is at +0x110
			void* hkRefA;             // 110 - hk ref-counted object (dec/ref in dtor)
			void* buf0;               // 118 - freed via MemoryManager
			void* buf1;               // 120 - freed via MemoryManager
			void* buf2;               // 128 - freed via MemoryManager
			void* buf3;               // 130 - freed via MemoryManager
		};

		// Useful filters observed in JobListManager building cloth jobs
		inline bool PlayerClothFilter(BSTransformSet* a_set)
		{
			using func_t = bool (*)(BSTransformSet*);
			// 0x7FF66408DF50 - 0x7FF6633D0000 = 0xCBDF50
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0xCBDF50 };
			return func(a_set);
		}

		inline bool NonPlayerClothFilter(BSTransformSet* a_set)
		{
			using func_t = bool (*)(BSTransformSet*);
			// 0x7FF66408DFA0 - 0x7FF6633D0000 = 0xCBDFA0
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0xCBDFA0 };
			return func(a_set);
		}
	}
}
