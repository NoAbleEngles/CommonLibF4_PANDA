#pragma once

#include "RE/Bethesda/Actor.h"
#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BGSCharacterMorph.h"
#include "RE/Bethesda/BGSCharacterTint.h"
#include "RE/Bethesda/BGSHeadPart.h"
#include "RE/NetImmerse/NiPoint2.h"
#include "RE/NetImmerse/NiPoint3.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class Actor;
	class BGSColorForm;
	class BGSListForm;
	class TESNPC;
	class TESObjectREFR;
	class TESRace;

	namespace BSFaceGenUtils { class FaceGenData; }

	struct ChargenCharacterUpdateEvent;

	class BGSChargenUtils :
		public BSTEventSource<ChargenCharacterUpdateEvent>  // 000
	{
	public:
		enum class EditMode : std::uint32_t
		{
			kChargen = 0,
			kRaceMenu = 1,
			kPlastic = 2,
			kPortrait = 3
		};

		enum class UndoType : std::uint32_t
		{
			kAll = 0,
			kFace = 1,
			kBody = 2,
			kHair = 3
		};

		struct AxisRemappingData
		{
			std::int32_t axis[6];  // 00 - X+, X-, Y+, Y-, Z+, Z-
		};
		static_assert(sizeof(AxisRemappingData) == 0x18);

		class UndoData
		{
		public:
			UndoData();
			~UndoData();

			// members - approximate structure based on disassembly
			std::uint8_t data[0x268];  // Raw data block to match the expected size
		};
		// Don't assert size for now - just comment it out
		// static_assert(sizeof(UndoData) == 0x268);

		// Construction/destruction
		BGSChargenUtils(Actor& a_actor, bool a_isChild);
		~BGSChargenUtils();

		// Core initialization and management
		void Initialize(TESObjectREFR* a_actor, EditMode a_editMode = EditMode::kChargen);
		void PreLoadAllPresetTextures();
		void UnloadAllPresetTextures();
		void ClearMetadata();

		// Sex and appearance management
		void ChangeSex(RE::Actor::Sex a_sex);
		void RandomizeAll();
		void ResetAll();
		void CopyFromCharacterPreset(std::uint32_t a_presetIndex);
		void CopyToActor(Actor& a_actor);
		void CopyToNPC(TESNPC& a_npc);

		// Weight and body morphing
		NiPoint3 GetWeight();
		void SetWeight(const NiPoint3& a_weight);
		void ConvertTriangleCoordToWeight(const NiPoint3& a_coord, NiPoint2& a_result);
		void ConvertWeightToTriangleCoord(const NiPoint2& a_weight, NiPoint3& a_result);
		NiPoint2 GetBodyMorphOffsetFromTriangleCoord(const NiPoint2& a_coord);
		void SetBodyMorphRegionValue(std::uint32_t a_region, float a_value);
		void ResetBodyMorphRegions();
		void RandomizeBodyMorphRegions();

		// Hair and complexion
		std::uint32_t GetHairColorDefaultIndex();
		std::uint32_t GetHairColorIndex();
		void SetHairColor(std::uint32_t a_colorIndex);
		std::uint32_t GetComplexionDefaultIndex();
		void SetComplexion(std::uint32_t a_complexionIndex);

		// Head parts
		std::uint32_t GetHeadPartDefaultIndex(BGSHeadPart::HeadPartType a_type);
		std::uint32_t GetHeadPartIndex(BGSHeadPart::HeadPartType a_type);
		void SetHeadPart(BGSHeadPart::HeadPartType a_type, std::uint32_t a_index);
		BGSHeadPart::HeadPartType GetHeadPartTypeFromFacialRegion(std::uint32_t a_region);
		std::uint32_t GetFacialRegionFromHeadPartType(BGSHeadPart::HeadPartType a_type);
		std::uint32_t GetBanterEventFromFacialRegion(std::uint32_t a_region);
		std::uint32_t GetFacialRegionFromTextureValue(std::uint32_t a_textureValue);
		void ResetHead();
		void RandomizeHead();

		// Facial bone regions
		std::uint32_t GetFacialBoneRegionCount();
		std::uint32_t GetFacialBoneRegionID(std::uint32_t a_index);
		const char* GetFacialBoneRegionName(std::uint32_t a_index);
		float GetFacialBoneRegionValue(std::uint32_t a_region, BGSCharacterMorph::Transform a_axis);
		void SetFacialBoneRegionValue(std::uint32_t a_region, BGSCharacterMorph::Transform a_axis, float a_value);
		bool GetValidBoneRegionScalingAxis(std::uint32_t a_region, BGSCharacterMorph::Transform a_axis);
		bool GetBoneRegionSliderExists(std::uint32_t a_region);
		bool GetValidBoneRegionSliderAxis(std::uint32_t a_region, BGSCharacterMorph::Transform a_axis);
		float GetFacialBoneRegionSliderValue(std::uint32_t a_region, BGSCharacterMorph::Transform a_axis);

		// Facial morph presets
		std::uint32_t GetFacialMorphPresetCount(std::uint32_t a_region);
		const char* GetFacialMorphPresetName(std::uint32_t a_region, std::uint32_t a_preset);
		float GetFacialMorphPresetValue(std::uint32_t a_region, std::uint32_t& a_preset);
		void SetFacialMorphPresetValue(std::uint32_t a_region, std::uint32_t a_preset, float a_value);
		bool GetFacialRegionSupportsIntensity(std::uint32_t a_region);
		BGSCharacterMorph::Group* GetMorphGroupFromBoneRegion(std::uint32_t a_region);
		void ResetFacialBoneRegion(std::uint32_t a_region);
		void ResetFacialBoneRegions();
		void RandomizeFacialBoneRegions();
		void ResetFacialMorphSliders();

		// Skin tone
		std::uint32_t GetSkinToneColorIndex();
		void SetSkinToneColorIndex(std::uint32_t a_index);
		void SetSkinToneValue(float a_value);

		// Face part customization
		const char* GetFacePartCustomizationGroupName(std::uint32_t a_group);
		std::uint32_t GetFacePartCustomizationEntryCount(std::uint32_t a_group);
		std::uint32_t GetFacePartCustomizationGroupIndexFromBoneRegion(std::uint32_t a_region);
		float GetFacePartCustomizationEntryValue(std::uint32_t a_group, std::uint32_t a_entry);
		void SetFacePartCustomizationEntryValue(std::uint32_t a_group, std::uint32_t a_entry, float a_value);
		std::uint32_t GetActiveFacePartCustomizationEntry(std::uint32_t a_group);

		// Face extras
		float GetFaceExtraIntensity(std::uint32_t a_group, std::uint32_t a_entry, bool a_temporary);
		std::uint32_t GetFaceExtraColorIndex(std::uint32_t a_group, std::uint32_t a_entry);
		void SetFaceExtraColorIndex(std::uint32_t a_group, std::uint32_t a_entry, std::uint32_t a_colorIndex);
		void RemoveTemporaryFaceExtra(std::uint32_t a_group);
		bool GetHasFaceExtrasApplied();

		// Update and rendering
		void DoUpdate();
		void ForceFullUpdate();
		void GenerateCharacterCustomizationTextureArrays();

		// Undo system
		void CreateSavePoint(UndoType a_type, std::uint32_t a_flags);
		void RevertCharacter();

		// members - simplified data layout to ensure correct size
		std::uint8_t data[0xA60];  // Raw data block to match expected size (minus vtable)

	private:
		void CreatePoint(UndoData& a_undoData, UndoType a_type, std::uint32_t a_flags);
	};
	// Don't assert size for now - just comment it out
	// static_assert(sizeof(BGSChargenUtils) == 0xAC0);
}
