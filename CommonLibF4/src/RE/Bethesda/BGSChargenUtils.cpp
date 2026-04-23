#include "C:/cpp/CommonLibF4/build/CommonLibF4/CMakeFiles/CommonLibF4.dir/Release/cmake_pch.hxx"
#include "RE/Bethesda/BGSChargenUtils.h"
#include "RE/Bethesda/Actor.h"
#include "RE/Bethesda/BGSCharacterMorph.h"
#include "RE/Bethesda/BGSCharacterTint.h"
#include "RE/Bethesda/BGSHeadPart.h"
#include "RE/Bethesda/TESObjectREFRs.h"
#include "REL/Relocation.h"

namespace RE
{
	// Constructor - offset 0x6AA970 (7FF66407AF70 - 7FF6633D1000)
	BGSChargenUtils::BGSChargenUtils(Actor& a_actor, bool a_isChild)
	{
		using func_t = void (*)(BGSChargenUtils*, Actor&, bool);
		REL::Relocation<func_t> func{ REL::Offset(0x6AA970) };
		func(this, a_actor, a_isChild);
	}

	// Destructor - offset 0x6AA290 (7FF66407B290 - 7FF6633D1000)
	BGSChargenUtils::~BGSChargenUtils()
	{
		using func_t = void (*)(BGSChargenUtils*);
		REL::Relocation<func_t> func{ REL::Offset(0x6AA290) };
		func(this);
	}

	// Initialize - offset 0x6AA620 (7FF66407B620 - 7FF6633D1000)
	void BGSChargenUtils::Initialize(TESObjectREFR* a_actor, EditMode a_editMode)
	{
		using func_t = decltype(&BGSChargenUtils::Initialize);
		REL::Relocation<func_t> func{ REL::Offset(0x6AA620) };
		return func(this, a_actor, a_editMode);
	}

	// PreLoadAllPresetTextures - offset 0x6AB810 (7FF66407C810 - 7FF6633D1000)
	void BGSChargenUtils::PreLoadAllPresetTextures()
	{
		using func_t = decltype(&BGSChargenUtils::PreLoadAllPresetTextures);
		REL::Relocation<func_t> func{ REL::Offset(0x6AB810) };
		return func(this);
	}

	// UnloadAllPresetTextures - offset 0x6AB850 (7FF66407C850 - 7FF6633D1000)
	void BGSChargenUtils::UnloadAllPresetTextures()
	{
		using func_t = decltype(&BGSChargenUtils::UnloadAllPresetTextures);
		REL::Relocation<func_t> func{ REL::Offset(0x6AB850) };
		return func(this);
	}

	// ClearMetadata - offset 0x6AB870 (7FF66407C870 - 7FF6633D1000)
	void BGSChargenUtils::ClearMetadata()
	{
		using func_t = decltype(&BGSChargenUtils::ClearMetadata);
		REL::Relocation<func_t> func{ REL::Offset(0x6AB870) };
		return func(this);
	}

	// ChangeSex - offset 0x6ABB10 (7FF66407CB10 - 7FF6633D1000)
	void BGSChargenUtils::ChangeSex(RE::Actor::Sex a_sex)
	{
		using func_t = decltype(&BGSChargenUtils::ChangeSex);
		REL::Relocation<func_t> func{ REL::Offset(0x6ABB10) };
		return func(this, a_sex);
	}

	// RandomizeAll - offset 0x6ABC20 (7FF66407CC20 - 7FF6633D1000)
	void BGSChargenUtils::RandomizeAll()
	{
	 using func_t = decltype(&BGSChargenUtils::RandomizeAll);
	 REL::Relocation<func_t> func{ REL::Offset(0x6ABC20) };
	 return func(this);
	}

	// ResetAll - offset 0x6ABCB0 (7FF66407CCB0 - 7FF6633D1000)
	void BGSChargenUtils::ResetAll()
	{
		using func_t = decltype(&BGSChargenUtils::ResetAll);
		REL::Relocation<func_t> func{ REL::Offset(0x6ABCB0) };
		return func(this);
	}

	// CopyFromCharacterPreset - offset 0x6ABD40 (7FF66407CD40 - 7FF6633D1000)
	void BGSChargenUtils::CopyFromCharacterPreset(std::uint32_t a_presetIndex)
	{
		using func_t = decltype(&BGSChargenUtils::CopyFromCharacterPreset);
		REL::Relocation<func_t> func{ REL::Offset(0x6ABD40) };
		return func(this, a_presetIndex);
	}

	// CopyToActor - offset 0x6ABDB0 (7FF66407CDB0 - 7FF6633D1000)
	void BGSChargenUtils::CopyToActor(Actor& a_actor)
	{
		using func_t = decltype(&BGSChargenUtils::CopyToActor);
		REL::Relocation<func_t> func{ REL::Offset(0x6ABDB0) };
		return func(this, a_actor);
	}

	// CopyToNPC - offset 0x6ABDD0 (7FF66407CDD0 - 7FF6633D1000)
	void BGSChargenUtils::CopyToNPC(TESNPC& a_npc)
	{
		using func_t = void (*)(BGSChargenUtils*, TESNPC&);
		REL::Relocation<func_t> func{ REL::Offset(0x6ABDD0) };
		return func(this, a_npc);
	}

	// GetWeight - offset 0x6ABE40 (7FF66407CE40 - 7FF6633D1000)
	NiPoint3 BGSChargenUtils::GetWeight()
	{
		using func_t = decltype(&BGSChargenUtils::GetWeight);
		REL::Relocation<func_t> func{ REL::Offset(0x6ABE40) };
		return func(this);
	}

	// SetWeight - offset 0x6ABE60 (7FF66407CE60 - 7FF6633D1000)
	void BGSChargenUtils::SetWeight(const NiPoint3& a_weight)
	{
		using func_t = decltype(&BGSChargenUtils::SetWeight);
		REL::Relocation<func_t> func{ REL::Offset(0x6ABE60) };
		return func(this, a_weight);
	}

	// ConvertTriangleCoordToWeight - offset 0x6ABEA0 (7FF66407CEA0 - 7FF6633D1000)
	void BGSChargenUtils::ConvertTriangleCoordToWeight(const NiPoint3& a_coord, NiPoint2& a_result)
	{
		using func_t = decltype(&BGSChargenUtils::ConvertTriangleCoordToWeight);
		REL::Relocation<func_t> func{ REL::Offset(0x6ABEA0) };
		return func(this, a_coord, a_result);
	}

	// ConvertWeightToTriangleCoord - offset 0x6AC1B0 (7FF66407D1B0 - 7FF6633D1000)
	void BGSChargenUtils::ConvertWeightToTriangleCoord(const NiPoint2& a_weight, NiPoint3& a_result)
	{
		using func_t = decltype(&BGSChargenUtils::ConvertWeightToTriangleCoord);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC1B0) };
		return func(this, a_weight, a_result);
	}

	// GetBodyMorphOffsetFromTriangleCoord - offset 0x6AC300 (7FF66407D300 - 7FF6633D1000)
	NiPoint2 BGSChargenUtils::GetBodyMorphOffsetFromTriangleCoord(const NiPoint2& a_coord)
	{
		using func_t = decltype(&BGSChargenUtils::GetBodyMorphOffsetFromTriangleCoord);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC300) };
		return func(this, a_coord);
	}

	// SetBodyMorphRegionValue - offset 0x6AC370 (7FF66407D370 - 7FF6633D1000)
	void BGSChargenUtils::SetBodyMorphRegionValue(std::uint32_t a_region, float a_value)
	{
		using func_t = decltype(&BGSChargenUtils::SetBodyMorphRegionValue);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC370) };
		return func(this, a_region, a_value);
	}

	// ResetBodyMorphRegions - offset 0x6AC3B0 (7FF66407D3B0 - 7FF6633D1000)
	void BGSChargenUtils::ResetBodyMorphRegions()
	{
	 using func_t = decltype(&BGSChargenUtils::ResetBodyMorphRegions);
	 REL::Relocation<func_t> func{ REL::Offset(0x6AC3B0) };
	 return func(this);
	}

	// RandomizeBodyMorphRegions - offset 0x6AC400 (7FF66407D400 - 7FF6633D1000)
	void BGSChargenUtils::RandomizeBodyMorphRegions()
	{
		using func_t = decltype(&BGSChargenUtils::RandomizeBodyMorphRegions);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC400) };
		return func(this);
	}

	// GetHairColorDefaultIndex - offset 0x6AC460 (7FF66407D460 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetHairColorDefaultIndex()
	{
		using func_t = decltype(&BGSChargenUtils::GetHairColorDefaultIndex);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC460) };
		return func(this);
	}

	// GetHairColorIndex - offset 0x6AC4E0 (7FF66407D4E0 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetHairColorIndex()
	{
		using func_t = decltype(&BGSChargenUtils::GetHairColorIndex);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC4E0) };
		return func(this);
	}

	// SetHairColor - offset 0x6AC540 (7FF66407D540 - 7FF6633D1000)
	void BGSChargenUtils::SetHairColor(std::uint32_t a_colorIndex)
	{
		using func_t = decltype(&BGSChargenUtils::SetHairColor);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC540) };
		return func(this, a_colorIndex);
	}

	// GetComplexionDefaultIndex - offset 0x6AC590 (7FF66407D590 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetComplexionDefaultIndex()
	{
		using func_t = decltype(&BGSChargenUtils::GetComplexionDefaultIndex);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC590) };
		return func(this);
	}

	// SetComplexion - offset 0x6AC680 (7FF66407D680 - 7FF6633D1000)
	void BGSChargenUtils::SetComplexion(std::uint32_t a_complexionIndex)
	{
		using func_t = decltype(&BGSChargenUtils::SetComplexion);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC680) };
		return func(this, a_complexionIndex);
	}

	// GetHeadPartDefaultIndex - offset 0x6AC6D0 (7FF66407D6D0 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetHeadPartDefaultIndex(BGSHeadPart::HeadPartType a_type)
	{
		using func_t = decltype(&BGSChargenUtils::GetHeadPartDefaultIndex);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC6D0) };
		return func(this, a_type);
	}

	// GetHeadPartIndex - offset 0x6AC760 (7FF66407D760 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetHeadPartIndex(BGSHeadPart::HeadPartType a_type)
	{
		using func_t = decltype(&BGSChargenUtils::GetHeadPartIndex);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC760) };
		return func(this, a_type);
	}

	// SetHeadPart - offset 0x6AC7D0 (7FF66407D7D0 - 7FF6633D1000)
	void BGSChargenUtils::SetHeadPart(BGSHeadPart::HeadPartType a_type, std::uint32_t a_index)
	{
		using func_t = decltype(&BGSChargenUtils::SetHeadPart);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC7D0) };
		return func(this, a_type, a_index);
	}

	// GetHeadPartTypeFromFacialRegion - offset 0x6AC8D0 (7FF66407D8D0 - 7FF6633D1000)
	BGSHeadPart::HeadPartType BGSChargenUtils::GetHeadPartTypeFromFacialRegion(std::uint32_t a_region)
	{
		using func_t = decltype(&BGSChargenUtils::GetHeadPartTypeFromFacialRegion);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC8D0) };
		return func(this, a_region);
	}

	// GetFacialRegionFromHeadPartType - offset 0x6AC910 (7FF66407D910 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetFacialRegionFromHeadPartType(BGSHeadPart::HeadPartType a_type)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacialRegionFromHeadPartType);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC910) };
		return func(this, a_type);
	}

	// GetBanterEventFromFacialRegion - offset 0x6AC9A0 (7FF66407D9A0 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetBanterEventFromFacialRegion(std::uint32_t a_region)
	{
		using func_t = decltype(&BGSChargenUtils::GetBanterEventFromFacialRegion);
		REL::Relocation<func_t> func{ REL::Offset(0x6AC9A0) };
		return func(this, a_region);
	}

	// GetFacialRegionFromTextureValue - offset 0x6ACA30 (7FF66407DA30 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetFacialRegionFromTextureValue(std::uint32_t a_textureValue)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacialRegionFromTextureValue);
		REL::Relocation<func_t> func{ REL::Offset(0x6ACA30) };
		return func(this, a_textureValue);
	}

	// ResetHead - offset 0x6ACAC0 (7FF66407DAC0 - 7FF6633D1000)
	void BGSChargenUtils::ResetHead()
	{
		using func_t = decltype(&BGSChargenUtils::ResetHead);
		REL::Relocation<func_t> func{ REL::Offset(0x6ACAC0) };
		return func(this);
	}

	// RandomizeHead - offset 0x6ACC00 (7FF66407DC00 - 7FF6633D1000)
	void BGSChargenUtils::RandomizeHead()
	{
		using func_t = decltype(&BGSChargenUtils::RandomizeHead);
		REL::Relocation<func_t> func{ REL::Offset(0x6ACC00) };
		return func(this);
	}

	// GetFacialBoneRegionCount - offset 0x6ACD20 (7FF66407DD20 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetFacialBoneRegionCount()
	{
		using func_t = decltype(&BGSChargenUtils::GetFacialBoneRegionCount);
		REL::Relocation<func_t> func{ REL::Offset(0x6ACD20) };
		return func(this);
	}

	// GetFacialBoneRegionID - offset 0x6ACD70 (7FF66407DD70 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetFacialBoneRegionID(std::uint32_t a_index)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacialBoneRegionID);
		REL::Relocation<func_t> func{ REL::Offset(0x6ACD70) };
		return func(this, a_index);
	}

	// GetFacialBoneRegionName - offset 0x6ACDD0 (7FF66407DDD0 - 7FF6633D1000)
	const char* BGSChargenUtils::GetFacialBoneRegionName(std::uint32_t a_index)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacialBoneRegionName);
		REL::Relocation<func_t> func{ REL::Offset(0x6ACDD0) };
		return func(this, a_index);
	}

	// GetFacialBoneRegionValue - offset 0x6ACE10 (7FF66407DE10 - 7FF6633D1000)
	float BGSChargenUtils::GetFacialBoneRegionValue(std::uint32_t a_region, BGSCharacterMorph::Transform a_axis)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacialBoneRegionValue);
		REL::Relocation<func_t> func{ REL::Offset(0x6ACE10) };
		return func(this, a_region, a_axis);
	}

	// SetFacialBoneRegionValue - offset 0x6AD010 (7FF66407E010 - 7FF6633D1000)
	void BGSChargenUtils::SetFacialBoneRegionValue(std::uint32_t a_region, BGSCharacterMorph::Transform a_axis, float a_value)
	{
		using func_t = decltype(&BGSChargenUtils::SetFacialBoneRegionValue);
		REL::Relocation<func_t> func{ REL::Offset(0x6AD010) };
		return func(this, a_region, a_axis, a_value);
	}

	// GetValidBoneRegionScalingAxis - offset 0x6AD210 (7FF66407E210 - 7FF6633D1000)
	bool BGSChargenUtils::GetValidBoneRegionScalingAxis(std::uint32_t a_region, BGSCharacterMorph::Transform a_axis)
	{
		using func_t = decltype(&BGSChargenUtils::GetValidBoneRegionScalingAxis);
		REL::Relocation<func_t> func{ REL::Offset(0x6AD210) };
		return func(this, a_region, a_axis);
	}

	// GetBoneRegionSliderExists - offset 0x6AD320 (7FF66407E320 - 7FF6633D1000)
	bool BGSChargenUtils::GetBoneRegionSliderExists(std::uint32_t a_region)
	{
		using func_t = decltype(&BGSChargenUtils::GetBoneRegionSliderExists);
		REL::Relocation<func_t> func{ REL::Offset(0x6AD320) };
		return func(this, a_region);
	}

	// GetValidBoneRegionSliderAxis - offset 0x6AD410 (7FF66407E410 - 7FF6633D1000)
	bool BGSChargenUtils::GetValidBoneRegionSliderAxis(std::uint32_t a_region, BGSCharacterMorph::Transform a_axis)
	{
		using func_t = decltype(&BGSChargenUtils::GetValidBoneRegionSliderAxis);
		REL::Relocation<func_t> func{ REL::Offset(0x6AD410) };
		return func(this, a_region, a_axis);
	}

	// GetFacialBoneRegionSliderValue - offset 0x6AD550 (7FF66407E550 - 7FF6633D1000)
	float BGSChargenUtils::GetFacialBoneRegionSliderValue(std::uint32_t a_region, BGSCharacterMorph::Transform a_axis)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacialBoneRegionSliderValue);
		REL::Relocation<func_t> func{ REL::Offset(0x6AD550) };
		return func(this, a_region, a_axis);
	}

	// GetFacialMorphPresetCount - offset 0x6ADA60 (7FF66407EA60 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetFacialMorphPresetCount(std::uint32_t a_region)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacialMorphPresetCount);
		REL::Relocation<func_t> func{ REL::Offset(0x6ADA60) };
		return func(this, a_region);
	}

	// GetFacialMorphPresetName - offset 0x6ADB10 (7FF66407EB10 - 7FF6633D1000)
	const char* BGSChargenUtils::GetFacialMorphPresetName(std::uint32_t a_region, std::uint32_t a_preset)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacialMorphPresetName);
		REL::Relocation<func_t> func{ REL::Offset(0x6ADB10) };
		return func(this, a_region, a_preset);
	}

	// GetFacialMorphPresetValue - offset 0x6ADBE0 (7FF66407EBE0 - 7FF6633D1000)
	float BGSChargenUtils::GetFacialMorphPresetValue(std::uint32_t a_region, std::uint32_t& a_preset)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacialMorphPresetValue);
		REL::Relocation<func_t> func{ REL::Offset(0x6ADBE0) };
		return func(this, a_region, a_preset);
	}

	// SetFacialMorphPresetValue - offset 0x6ADD00 (7FF66407ED00 - 7FF6633D1000)
	void BGSChargenUtils::SetFacialMorphPresetValue(std::uint32_t a_region, std::uint32_t a_preset, float a_value)
	{
		using func_t = decltype(&BGSChargenUtils::SetFacialMorphPresetValue);
		REL::Relocation<func_t> func{ REL::Offset(0x6ADD00) };
		return func(this, a_region, a_preset, a_value);
	}

	// GetFacialRegionSupportsIntensity - offset 0x6AE1D0 (7FF66407F1D0 - 7FF6633D1000)
	bool BGSChargenUtils::GetFacialRegionSupportsIntensity(std::uint32_t a_region)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacialRegionSupportsIntensity);
		REL::Relocation<func_t> func{ REL::Offset(0x6AE1D0) };
		return func(this, a_region);
	}

	// GetMorphGroupFromBoneRegion - offset 0x6AE370 (7FF66407F370 - 7FF6633D1000)
	BGSCharacterMorph::Group* BGSChargenUtils::GetMorphGroupFromBoneRegion(std::uint32_t a_region)
	{
		using func_t = decltype(&BGSChargenUtils::GetMorphGroupFromBoneRegion);
		REL::Relocation<func_t> func{ REL::Offset(0x6AE370) };
		return func(this, a_region);
	}

	// ResetFacialBoneRegion - offset 0x6AE400 (7FF66407F400 - 7FF6633D1000)
	void BGSChargenUtils::ResetFacialBoneRegion(std::uint32_t a_region)
	{
		using func_t = decltype(&BGSChargenUtils::ResetFacialBoneRegion);
		REL::Relocation<func_t> func{ REL::Offset(0x6AE400) };
		return func(this, a_region);
	}

	// ResetFacialBoneRegions - offset 0x6AE480 (7FF66407F480 - 7FF6633D1000)
	void BGSChargenUtils::ResetFacialBoneRegions()
	{
		using func_t = decltype(&BGSChargenUtils::ResetFacialBoneRegions);
		REL::Relocation<func_t> func{ REL::Offset(0x6AE480) };
		return func(this);
	}

	// RandomizeFacialBoneRegions - offset 0x6AE570 (7FF66407F570 - 7FF6633D1000)
	void BGSChargenUtils::RandomizeFacialBoneRegions()
	{
		using func_t = decltype(&BGSChargenUtils::RandomizeFacialBoneRegions);
		REL::Relocation<func_t> func{ REL::Offset(0x6AE570) };
		return func(this);
	}

	// ResetFacialMorphSliders - offset 0x6AE6D0 (7FF66407F6D0 - 7FF6633D1000)
	void BGSChargenUtils::ResetFacialMorphSliders()
	{
		using func_t = decltype(&BGSChargenUtils::ResetFacialMorphSliders);
		REL::Relocation<func_t> func{ REL::Offset(0x6AE6D0) };
		return func(this);
	}

	// GetSkinToneColorIndex - offset 0x6AE8D0 (7FF66407F8D0 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetSkinToneColorIndex()
	{
		using func_t = decltype(&BGSChargenUtils::GetSkinToneColorIndex);
		REL::Relocation<func_t> func{ REL::Offset(0x6AE8D0) };
		return func(this);
	}

	// SetSkinToneColorIndex - offset 0x6AE980 (7FF66407F980 - 7FF6633D1000)
	void BGSChargenUtils::SetSkinToneColorIndex(std::uint32_t a_index)
	{
		using func_t = decltype(&BGSChargenUtils::SetSkinToneColorIndex);
		REL::Relocation<func_t> func{ REL::Offset(0x6AE980) };
		return func(this, a_index);
	}

	// SetSkinToneValue - offset 0x6AEAA0 (7FF66407FAA0 - 7FF6633D1000)
	void BGSChargenUtils::SetSkinToneValue(float a_value)
	{
		using func_t = decltype(&BGSChargenUtils::SetSkinToneValue);
		REL::Relocation<func_t> func{ REL::Offset(0x6AEAA0) };
		return func(this, a_value);
	}

	// GetFacePartCustomizationGroupName - offset 0x6AEBC0 (7FF66407FBC0 - 7FF6633D1000)
	const char* BGSChargenUtils::GetFacePartCustomizationGroupName(std::uint32_t a_group)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacePartCustomizationGroupName);
		REL::Relocation<func_t> func{ REL::Offset(0x6AEBC0) };
		return func(this, a_group);
	}

	// GetFacePartCustomizationEntryCount - offset 0x6AEBF0 (7FF66407FBF0 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetFacePartCustomizationEntryCount(std::uint32_t a_group)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacePartCustomizationEntryCount);
		REL::Relocation<func_t> func{ REL::Offset(0x6AEBF0) };
		return func(this, a_group);
	}

	// GetFacePartCustomizationGroupIndexFromBoneRegion - offset 0x6AECA0 (7FF66407FCA0 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetFacePartCustomizationGroupIndexFromBoneRegion(std::uint32_t a_region)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacePartCustomizationGroupIndexFromBoneRegion);
		REL::Relocation<func_t> func{ REL::Offset(0x6AECA0) };
		return func(this, a_region);
	}

	// GetFacePartCustomizationEntryValue - offset 0x6AED70 (7FF66407FD70 - 7FF6633D1000)
	float BGSChargenUtils::GetFacePartCustomizationEntryValue(std::uint32_t a_group, std::uint32_t a_entry)
	{
		using func_t = decltype(&BGSChargenUtils::GetFacePartCustomizationEntryValue);
		REL::Relocation<func_t> func{ REL::Offset(0x6AED70) };
		return func(this, a_group, a_entry);
	}

	// SetFacePartCustomizationEntryValue - offset 0x6AEE10 (7FF66407FE10 - 7FF6633D1000)
	void BGSChargenUtils::SetFacePartCustomizationEntryValue(std::uint32_t a_group, std::uint32_t a_entry, float a_value)
	{
		using func_t = decltype(&BGSChargenUtils::SetFacePartCustomizationEntryValue);
		REL::Relocation<func_t> func{ REL::Offset(0x6AEE10) };
		return func(this, a_group, a_entry, a_value);
	}

	// GetActiveFacePartCustomizationEntry - offset 0x6AEF40 (7FF66407FF40 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetActiveFacePartCustomizationEntry(std::uint32_t a_group)
	{
		using func_t = decltype(&BGSChargenUtils::GetActiveFacePartCustomizationEntry);
		REL::Relocation<func_t> func{ REL::Offset(0x6AEF40) };
		return func(this, a_group);
	}

	// GetFaceExtraIntensity - offset 0x6AF0D0 (7FF664080D0 - 7FF6633D1000)
	float BGSChargenUtils::GetFaceExtraIntensity(std::uint32_t a_group, std::uint32_t a_entry, bool a_temporary)
	{
		using func_t = decltype(&BGSChargenUtils::GetFaceExtraIntensity);
		REL::Relocation<func_t> func{ REL::Offset(0x6AF0D0) };
		return func(this, a_group, a_entry, a_temporary);
	}

	// GetFaceExtraColorIndex - offset 0x6AF4E0 (7FF6640804E0 - 7FF6633D1000)
	std::uint32_t BGSChargenUtils::GetFaceExtraColorIndex(std::uint32_t a_group, std::uint32_t a_entry)
	{
		using func_t = decltype(&BGSChargenUtils::GetFaceExtraColorIndex);
		REL::Relocation<func_t> func{ REL::Offset(0x6AF4E0) };
		return func(this, a_group, a_entry);
	}

	// SetFaceExtraColorIndex - offset 0x6AF640 (7FF664080640 - 7FF6633D1000)
	void BGSChargenUtils::SetFaceExtraColorIndex(std::uint32_t a_group, std::uint32_t a_entry, std::uint32_t a_colorIndex)
	{
		using func_t = decltype(&BGSChargenUtils::SetFaceExtraColorIndex);
		REL::Relocation<func_t> func{ REL::Offset(0x6AF640) };
		return func(this, a_group, a_entry, a_colorIndex);
	}

	// RemoveTemporaryFaceExtra - offset 0x6AF8B0 (7FF6640808B0 - 7FF6633D1000)
	void BGSChargenUtils::RemoveTemporaryFaceExtra(std::uint32_t a_group)
	{
		using func_t = decltype(&BGSChargenUtils::RemoveTemporaryFaceExtra);
		REL::Relocation<func_t> func{ REL::Offset(0x6AF8B0) };
		return func(this, a_group);
	}

	// GetHasFaceExtrasApplied - offset 0x6AF980 (7FF664080980 - 7FF6633D1000)
	bool BGSChargenUtils::GetHasFaceExtrasApplied()
	{
		using func_t = decltype(&BGSChargenUtils::GetHasFaceExtrasApplied);
		REL::Relocation<func_t> func{ REL::Offset(0x6AF980) };
		return func(this);
	}

	// DoUpdate - offset 0x6AFAC0 (7FF664080AC0 - 7FF6633D1000)
	void BGSChargenUtils::DoUpdate()
	{
		using func_t = decltype(&BGSChargenUtils::DoUpdate);
		REL::Relocation<func_t> func{ REL::Offset(0x6AFAC0) };
		return func(this);
	}

	// ForceFullUpdate - offset 0x6AFE20 (7FF664080E20 - 7FF6633D1000)
	void BGSChargenUtils::ForceFullUpdate()
	{
		using func_t = decltype(&BGSChargenUtils::ForceFullUpdate);
		REL::Relocation<func_t> func{ REL::Offset(0x6AFE20) };
		return func(this);
	}

	// CreateSavePoint - offset 0x6AFEF0 (7FF664080EF0 - 7FF6633D1000)
	void BGSChargenUtils::CreateSavePoint(UndoType a_type, std::uint32_t a_flags)
	{
		using func_t = decltype(&BGSChargenUtils::CreateSavePoint);
		REL::Relocation<func_t> func{ REL::Offset(0x6AFEF0) };
		return func(this, a_type, a_flags);
	}

	// RevertCharacter - offset 0x6AFF30 (7FF664080F30 - 7FF6633D1000)
	void BGSChargenUtils::RevertCharacter()
	{
		using func_t = decltype(&BGSChargenUtils::RevertCharacter);
		REL::Relocation<func_t> func{ REL::Offset(0x6AFF30) };
		return func(this);
	}

	// GenerateCharacterCustomizationTextureArrays - offset 0x6AFF60 (7FF664080F60 - 7FF6633D1000)
	void BGSChargenUtils::GenerateCharacterCustomizationTextureArrays()
	{
		using func_t = decltype(&BGSChargenUtils::GenerateCharacterCustomizationTextureArrays);
		REL::Relocation<func_t> func{ REL::Offset(0x6AFF60) };
		return func(this);
	}

	// CreatePoint - offset 0x6B01A0 (7FF6640811A0 - 7FF6633D1000)
	void BGSChargenUtils::CreatePoint(UndoData& a_undoData, UndoType a_type, std::uint32_t a_flags)
	{
		using func_t = void (*)(BGSChargenUtils*, UndoData&, UndoType, std::uint32_t);
		REL::Relocation<func_t> func{ REL::Offset(0x6B01A0) };
		return func(this, a_undoData, a_type, a_flags);
	}

	// UndoData constructor - offset 0x6B5AB0 (7FF664086AB0 - 7FF6633D1000)
	BGSChargenUtils::UndoData::UndoData()
	{
		using func_t = void (*)(UndoData*);
		REL::Relocation<func_t> func{ REL::Offset(0x6B5AB0) };
		func(this);
	}

	// UndoData destructor - offset 0x6B6740 (7FF664087740 - 7FF6633D1000)
	BGSChargenUtils::UndoData::~UndoData()
	{
		using func_t = void (*)(UndoData*);
		REL::Relocation<func_t> func{ REL::Offset(0x6B6740) };
		func(this);
	}
}
