#pragma once

#include "RE/NetImmerse/NiNode.h"
#include "RE/NetImmerse/NiMatrix3.h"
#include "RE/NetImmerse/NiPoint3.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "REL/Relocation.h"

namespace RE
{
	class BSFaceGenAnimationData;
	class BSTriShape;
	class NiUpdateData;
	class NiCloningProcess;
	class TESNPC;
	class Actor;
	class BGSHeadPart;
	class TESObjectREFR;
	class BSGeometry;
	class NiAVObject;
	class NiColorA;
	class NiColor;
	class NiBinaryStream;

	namespace BSResource
	{
		struct ID;
		struct Entry;
		struct RHandleType;
		struct EntryDB;
	}

	namespace BGSCharacterTint { class Entry; }

	class __declspec(novtable) BSFaceGenNiNode :
		public NiNode  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSFaceGenNiNode };
		static constexpr auto VTABLE{ VTABLE::BSFaceGenNiNode };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSFaceGenNiNode };

		struct FaceGenUpdateData
		{
			BSTriShape* triShape;          // 00
			void* morphDataHead;           // 08 - BSFaceGenMorphDataHead*
			std::uint32_t vertexCount;     // 10
			bool updateRequired;           // 14
		};

		BSFaceGenNiNode();
		virtual ~BSFaceGenNiNode();

		// override (NiNode)
		virtual NiObject* CreateClone(NiCloningProcess& a_cloning) override;                               // 17
		virtual void UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_flags) override;            // 29

		// add
		virtual void SetAnimationData(BSFaceGenAnimationData* a_animData);                                // 43
		virtual void FixSkinInstances(NiNode* a_node, BSTriShape* a_triShape, bool a_flag);               // 44
		virtual void FixSkinInstances(NiNode* a_node, BSTriShape* a_triShape, 
											BSTScrapHashMap<BSFixedString, NiAVObject*>& a_map, bool a_flag);  // 45
		virtual void UpdateAllChildrenMorphData(bool a_forceUpdate);                                      // 46
		virtual void ApplyFacialMorphs(FaceGenUpdateData& a_updateData);                                  // 47
		virtual bool QMorphLoaded(std::uint8_t a_morphIndex);                                             // 48
		virtual void ResetFaceBaseMorphData();                                                            // 49
		virtual void ClearMorphingDataFromChildren();                                                     // 4A
		virtual void UpdateMorphing(NiUpdateData& a_data);                                                // 4B

		void CopyMembers(BSFaceGenNiNode* a_src, NiCloningProcess& a_cloning);

		F4_HEAP_REDEFINE_ALIGNED_NEW(BSFaceGenNiNode);

		// members
		NiMatrix3 headPartTransform[3];                  // 140 - head part transforms (base, expression, modifier)
		BSFaceGenAnimationData* animationData;           // 1D0 - using raw pointer to avoid template issues
		float lastUpdateTime;                            // 1D8 - set to -1.0 during construction
		std::uint16_t flags;                             // 1DC
		std::uint8_t partFlags;                          // 1DE
		std::uint8_t pad1DF;                             // 1DF
		void* resourceHandle;                            // 1E0 - BSResource::RHandleType handle
		std::uint64_t pad1E8;                            // 1E8
	};
	static_assert(sizeof(BSFaceGenNiNode) == 0x1F0);

	//------------------------------------------------------------------------------
	// BSFaceGenUtils - thin wrappers to the game's FaceGen helper namespace
	// Model and style based on RE::BSClothUtils in BSBound.h
	// Base address observed at 0x7FF6633D0000 (FO4 1.10.163)
	//------------------------------------------------------------------------------
	namespace BSFaceGenUtils
	{
		// Helper FaceGen working set used across many APIs
		class FaceGenData
		{
		public:
			// ctor/dtor
			FaceGenData()
			{
				using func_t = FaceGenData* (*)(FaceGenData*);
				REL::Relocation<func_t> func{ REL::Module::get().base() + 0x687850 };
				func(this);
			}

			~FaceGenData()
			{
				// scalar deleting dtor wrapper with flags=0
				using func_t = void (*)(FaceGenData*, std::uint32_t);
				REL::Relocation<func_t> func{ REL::Module::get().base() + 0x67D860 };
				func(this, 0);
			}

			void Reset()
			{
				using func_t = void (*)(FaceGenData*);
				REL::Relocation<func_t> func{ REL::Module::get().base() + 0x687A00 };
				return func(this);
			}

			void* FindLayer(BSResource::ID& a_id)
			{
				using func_t = void* (*)(FaceGenData*, BSResource::ID&);
				REL::Relocation<func_t> func{ REL::Module::get().base() + 0x687890 };
				return func(this, a_id);
			}
		};

		// IO helpers
		inline std::size_t Read(NiBinaryStream& a_stream, void* a_dst, std::uint32_t a_size, std::uint32_t a_flags)
		{
			using func_t = std::size_t (*)(NiBinaryStream&, void*, std::uint32_t, std::uint32_t);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x66ACF0 };
			return func(a_stream, a_dst, a_size, a_flags);
		}

		// Morph helpers
		inline const char* GetFaceGenMorphText(std::uint32_t a_index)
		{
			using func_t = const char* (*)(std::uint32_t);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x687A70 };
			return func(a_index);
		}

		inline std::uint32_t GetFaceGenMorphFromText(const char* a_text)
		{
			using func_t = std::uint32_t (*)(const char*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x687AE0 };
			return func(a_text);
		}

		inline bool LoadFaceGenGeometry(NiPointer<BSTriShape>& a_outTri, const char* a_path)
		{
			using func_t = bool (*)(NiPointer<BSTriShape>&, const char*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x687B90 };
			return func(a_outTri, a_path);
		}

		inline bool LoadFaceGenMorphData(void* a_modelMeshData, const char* a_path, bool a_async)
		{
			using func_t = bool (*)(void*, const char*, bool);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x687C80 };
			return func(a_modelMeshData, a_path, a_async);
		}

		inline void* GetFaceGenMorphData(BSTriShape* a_tri)
		{
			using func_t = void* (*)(BSTriShape*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x687D10 };
			return func(a_tri);
		}

		inline void* GetFaceGenMorphDataHead(BSTriShape* a_tri)
		{
			using func_t = void* (*)(BSTriShape*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x687D80 };
			return func(a_tri);
		}

		inline void* GetFaceGenMorphDataHair(BSTriShape* a_tri)
		{
			using func_t = void* (*)(BSTriShape*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x687E10 };
			return func(a_tri);
		}

		// Coordinate utilities (matrix types elided as opaque pointers)
		inline void InitFaceGenCoord(void* a_coords /* FR2MatrixVTC<float> (&)[2][2] */)
		{
			using func_t = void (*)(void*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x687FE0 };
			return func(a_coords);
		}

		inline void ResetFaceGenCoord(void* a_coords /* FR2MatrixVTC<float> (&)[2][2] */)
		{
			using func_t = void (*)(void*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x688050 };
			return func(a_coords);
		}

		inline bool CoordsEqual(const void* a_coordsA, const void* a_coordsB)
		{
			using func_t = bool (*)(const void*, const void*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x6880F0 };
			return func(a_coordsA, a_coordsB);
		}

		inline void CopyFaceGenCoord(void* a_dst, void* a_src, bool a_copyScale, bool a_copyOffset)
		{
			using func_t = void (*)(void*, void*, bool, bool);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x6881B0 };
			return func(a_dst, a_src, a_copyScale, a_copyOffset);
		}

		inline void MergeFaceGenCoord(void* a_out, void* a_a, void* a_b, bool a_useB, float a_weight)
		{
			using func_t = void (*)(void*, void*, void*, bool, float);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x6882D0 };
			return func(a_out, a_a, a_b, a_useB, a_weight);
		}

		inline void BlendFaceCoord(float a_blend, void* a_out, void* a_a, void* a_b, bool a_bias)
		{
			using func_t = void (*)(float, void*, void*, void*, bool);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x688A50 };
			return func(a_blend, a_out, a_a, a_b, a_bias);
		}

		inline void ClampCoord(void* a_coords, float a_max)
		{
			using func_t = void (*)(void*, float);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x689040 };
			return func(a_coords, a_max);
		}

		inline bool GetAsNearestDetailDDSFile(char* a_outPath, int a_sex, std::uint32_t a_id, const char* a_inPath)
		{
			using func_t = bool (*)(char*, int, std::uint32_t, const char*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x689110 };
			return func(a_outPath, a_sex, a_id, a_inPath);
		}

		inline void CopyBaseVertsToBackBuffer(BSFaceGenNiNode* a_node)
		{
			using func_t = void (*)(BSFaceGenNiNode*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x6896F0 };
			return func(a_node);
		}

		inline void RemoveSkinInstances(BSFaceGenNiNode* a_node)
		{
			using func_t = void (*)(BSFaceGenNiNode*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x689710 };
			return func(a_node);
		}

		// Character creation and customization
		inline bool GenerateFaceCustomizationForNPC(TESNPC& a_npc,
			BSTArray<BGSCharacterTint::Entry*>& a_tints,
			FaceGenData& a_fgData,
			bool a_blocking)
		{
			using func_t = bool (*)(TESNPC&, BSTArray<BGSCharacterTint::Entry*>&, FaceGenData&, bool);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x6899A0 };
			return func(a_npc, a_tints, a_fgData, a_blocking);
		}

		inline std::uint32_t QCustomizationBufferSize()
		{
			using func_t = std::uint32_t (*)();
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x689BA0 };
			return func();
		}

		inline bool StartFaceCustomizationGenerationForNPC(TESNPC& a_npc,
			BSTArray<BGSCharacterTint::Entry*>& a_tints,
			FaceGenData& a_fgData,
			void* a_userData,
			std::uint32_t a_flags,
			bool a_async)
		{
			using func_t = bool (*)(TESNPC&, BSTArray<BGSCharacterTint::Entry*>&, FaceGenData&, void*, std::uint32_t, bool);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x689BB0 };
			return func(a_npc, a_tints, a_fgData, a_userData, a_flags, a_async);
		}

		inline void PollFaceCustomizationLoads(FaceGenData& a_fgData)
		{
			using func_t = void (*)(FaceGenData&);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68AA60 };
			return func(a_fgData);
		}

		inline void RenderFaceCustomizationTextures(FaceGenData& a_fgData, void* a_renderContext)
		{
			using func_t = void (*)(FaceGenData&, void*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68AAE0 };
			return func(a_fgData, a_renderContext);
		}

		inline bool VerifyFileOkay(const char* a_path, bool a_write)
		{
			using func_t = bool (*)(const char*, bool);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68AED0 };
			return func(a_path, a_write);
		}

		inline bool CreateHeadForNPC(TESNPC* a_npc,
			NiPointer<BSFaceGenNiNode>& a_outHead,
			bool a_highPoly,
			bool a_cache,
			void* a_pendingHeadData)
		{
			using func_t = bool (*)(TESNPC*, NiPointer<BSFaceGenNiNode>&, bool, bool, void*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68AFC0 };
			return func(a_npc, a_outHead, a_highPoly, a_cache, a_pendingHeadData);
		}

		inline bool BuildHeadNodeForNPC(TESNPC* a_npc,
			NiPointer<BSFaceGenNiNode>& a_outHead,
			void* a_rhandle,
			void* a_entry,
			NiPointer<NiNode>& a_outNode,
			void* a_entryDBTraits,
			void* a_modelDBTraits)
		{
			using func_t = bool (*)(TESNPC*, NiPointer<BSFaceGenNiNode>&, void*, void*, NiPointer<NiNode>&, void*, void*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68B3B0 };
			return func(a_npc, a_outHead, a_rhandle, a_entry, a_outNode, a_entryDBTraits, a_modelDBTraits);
		}

		inline void PrepareHeadPart(BSFaceGenNiNode* a_node, BGSHeadPart* a_part, TESNPC* a_npc, bool a_applyMorphs)
		{
			using func_t = void (*)(BSFaceGenNiNode*, BGSHeadPart*, TESNPC*, bool);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68B6E0 };
			return func(a_node, a_part, a_npc, a_applyMorphs);
		}

		inline void PreparePreprocessedHeadPart(TESNPC* a_npc, BSFaceGenNiNode* a_node, BGSHeadPart* a_part)
		{
			using func_t = void (*)(TESNPC*, BSFaceGenNiNode*, BGSHeadPart*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68BBC0 };
			return func(a_npc, a_node, a_part);
		}

		inline void PrepareHeadGeometry(TESNPC* a_npc, NiAVObject* a_obj, BGSHeadPart* a_part)
		{
			using func_t = void (*)(TESNPC*, NiAVObject*, BGSHeadPart*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68BC70 };
			return func(a_npc, a_obj, a_part);
		}

		inline void PrepareHeadForShaders(BSScrapArray<BGSHeadPart*>& a_parts, BSFaceGenNiNode* a_node, TESNPC* a_npc, void* a_pendingData)
		{
			using func_t = void (*)(BSScrapArray<BGSHeadPart*>&, BSFaceGenNiNode*, TESNPC*, void*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68BEB0 };
			return func(a_parts, a_node, a_npc, a_pendingData);
		}

		inline void PrepareHeadPartForShaders(BSFaceGenNiNode* a_node, BGSHeadPart* a_part, TESNPC* a_npc, void* a_pendingData)
		{
			using func_t = void (*)(BSFaceGenNiNode*, BGSHeadPart*, TESNPC*, void*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68BFC0 };
			return func(a_node, a_part, a_npc, a_pendingData);
		}

		inline void AddBoneTint(TESObjectREFR* a_ref, int a_index)
		{
			using func_t = void (*)(TESObjectREFR*, int);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68C3D0 };
			return func(a_ref, a_index);
		}

		inline void UpdateBodyTintColorsOnScene(NiAVObject* a_scene, NiColorA& a_color)
		{
			using func_t = void (*)(NiAVObject*, NiColorA&);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68C530 };
			return func(a_scene, a_color);
		}

		inline void UpdateFaceCustomizationTexturesOnScene(NiAVObject* a_scene, TESNPC* a_npc, bool a_isFemale, bool a_highQuality)
		{
			using func_t = void (*)(NiAVObject*, TESNPC*, bool, bool);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68C550 };
			return func(a_scene, a_npc, a_isFemale, a_highQuality);
		}

		inline void UpdateBodyTintOnActor(Actor* a_actor, NiColorA& a_color)
		{
			using func_t = void (*)(Actor*, NiColorA&);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68C5D0 };
			return func(a_actor, a_color);
		}

		inline void UpdateHairColorOnActor(Actor* a_actor, NiColor& a_color)
		{
			using func_t = void (*)(Actor*, NiColor&);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68C600 };
			return func(a_actor, a_color);
		}

		inline void UpdateFaceCustomizationTexturesOnActor(Actor* a_actor)
		{
			using func_t = void (*)(Actor*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68C630 };
			return func(a_actor);
		}

		inline void AddHeadPartOnActor(Actor* a_actor, BGSHeadPart* a_part)
		{
			using func_t = void (*)(Actor*, BGSHeadPart*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68C670 };
			return func(a_actor, a_part);
		}

		inline void RemoveHeadPartOnActor(Actor* a_actor, BGSHeadPart* a_part)
		{
			using func_t = void (*)(Actor*, BGSHeadPart*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68C7E0 };
			return func(a_actor, a_part);
		}

		inline void ReplaceHeadPartOnActor(Actor* a_actor, BGSHeadPart* a_old, BGSHeadPart* a_new)
		{
			using func_t = void (*)(Actor*, BGSHeadPart*, BGSHeadPart*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68C850 };
			return func(a_actor, a_old, a_new);
		}

		inline void ApplyGeneticsToActor(TESNPC& a_child, TESNPC& a_mother, TESNPC& a_father, TESNPC& a_template)
		{
			using func_t = void (*)(TESNPC&, TESNPC&, TESNPC&, TESNPC&);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68C900 };
			return func(a_child, a_mother, a_father, a_template);
		}

		inline void ApplyBlendedSkinTintToObject(NiAVObject* a_obj)
		{
			using func_t = void (*)(NiAVObject*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68CEC0 };
			return func(a_obj);
		}

		inline bool PickFaceRegion(TESObjectREFR* a_ref, NiPoint3& a_origin, NiPoint3& a_dir, std::uint32_t& a_regionOut, BSTArray<std::uint8_t>& a_buffer, std::uint32_t& a_width, bool a_worldRay)
		{
			using func_t = bool (*)(TESObjectREFR*, NiPoint3&, NiPoint3&, std::uint32_t&, BSTArray<std::uint8_t>&, std::uint32_t&, bool);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68CF70 };
			return func(a_ref, a_origin, a_dir, a_regionOut, a_buffer, a_width, a_worldRay);
		}

		inline void RemoveHairHighlight(BSTriShape* a_tri)
		{
			using func_t = void (*)(BSTriShape*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68DEE0 };
			return func(a_tri);
		}

		inline void RemoveHairHighlight(TESObjectREFR* a_ref)
		{
			using func_t = void (*)(TESObjectREFR*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68DF30 };
			return func(a_ref);
		}

		inline void HighlightHair(BSTriShape* a_tri)
		{
			using func_t = void (*)(BSTriShape*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68E000 };
			return func(a_tri);
		}

		inline void HighlightHair(TESObjectREFR* a_ref)
		{
			using func_t = void (*)(TESObjectREFR*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68E130 };
			return func(a_ref);
		}

		inline bool FindFace(TESObjectREFR* a_ref, BSTriShape*& a_outHead, BSTriShape*& a_outHair, BSTriShape*& a_outBeard, BSTriShape*& a_outBrows)
		{
			using func_t = bool (*)(TESObjectREFR*, BSTriShape*&, BSTriShape*&, BSTriShape*&, BSTriShape*&);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68E1B0 };
			return func(a_ref, a_outHead, a_outHair, a_outBeard, a_outBrows);
		}

		inline void AttachHeadHelper(TESNPC* a_npc, BSFaceGenNiNode* a_node, TESObjectREFR* a_owner, Actor* a_actor)
		{
			using func_t = void (*)(TESNPC*, BSFaceGenNiNode*, TESObjectREFR*, Actor*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68E210 };
			return func(a_npc, a_node, a_owner, a_actor);
		}

		inline void AddChildBoneNames(BSFixedString& a_parentBone, BSFixedString* a_outChildren, std::uint32_t& a_outCount, NiNode* a_root)
		{
			using func_t = void (*)(BSFixedString&, BSFixedString*, std::uint32_t&, NiNode*);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68F4F0 };
			return func(a_parentBone, a_outChildren, a_outCount, a_root);
		}

		inline void GetBlendedSkinTone(TESNPC& a_a, TESNPC& a_b)
		{
			using func_t = void (*)(TESNPC&, TESNPC&);
			REL::Relocation<func_t> func{ REL::Module::get().base() + 0x68FE40 };
			return func(a_a, a_b);
		}
	}
}
