#pragma once

#include "REL/Relocation.h"

namespace RE
{
	namespace RTTI_AE
	{
		// AE (Anniversary Edition / Next-Gen) RTTI IDs
		// OG IDs remain in RTTI_IDs.h
		// Usage in classes: static constexpr auto RTTI{ REL::REL_ID_VER(RTTI::ClassName, RTTI_AE::ClassName) };

		// Memory Management
		inline constexpr REL::ID IMemoryStoreBase{ 4858639 };
		inline constexpr REL::ID IMemoryStore{ 4858637 };
		inline constexpr REL::ID IMemoryHeap{ 4858649 };
		inline constexpr REL::ID ScrapHeap{ 4858641 };
		
		//Actor
		inline constexpr REL::ID ActorPackageData{ 4843528 };
		inline constexpr REL::ID EquippedItemData{ 4848794 };
		inline constexpr REL::ID EquippedWeaponData{ 4848796 };
		inline constexpr REL::ID MagicTarget{ 4847852 };
		inline constexpr REL::ID ActorState{ 4848596 };
		inline constexpr REL::ID IPostAnimationChannelUpdateFunctor{ 4848610 };

		//TESForm
		inline constexpr REL::ID TESForm{ 4839494 };
		inline constexpr REL::ID BGSKeyword{ 4839770 };
		inline constexpr REL::ID BGSLocationRefType{ 4839782 };
		inline constexpr REL::ID BGSAction{ 4842220 };
		inline constexpr REL::ID BGSTransform{ 4839810 };
		inline constexpr REL::ID BGSMenuIcon{ 4841930 };
		inline constexpr REL::ID TESGlobal{ 4840012 };
		inline constexpr REL::ID BGSDamageType{ 4841234 };
		inline constexpr REL::ID TESClass{ 4842350 };
		inline constexpr REL::ID TESEyes{ 4840530 };
		inline constexpr REL::ID EffectSetting{ 4839924 };
		inline constexpr REL::ID TESLandTexture{ 4841130 };
		inline constexpr REL::ID TESWeather{ 4841700 };
		inline constexpr REL::ID TESClimate{ 4841702 };
		inline constexpr REL::ID BGSShaderParticleGeometryData{ 4841682 };
		inline constexpr REL::ID BGSReferenceEffect{ 4839936 };
		inline constexpr REL::ID TESRegion{ 4841100 };
		inline constexpr REL::ID TESObjectCELL{ 4839496 };
		inline constexpr REL::ID TESObjectLAND{ 4841718 };
		inline constexpr REL::ID TESTopic{ 4840058 };
		inline constexpr REL::ID TESTopicInfo{ 4840056 };
		inline constexpr REL::ID TESIdleForm{ 4839556 };
		inline constexpr REL::ID TESLoadScreen{ 4842048 };
		inline constexpr REL::ID TESObjectANIO{ 4841472 };
		inline constexpr REL::ID TESEffectShader{ 4839912 };
		inline constexpr REL::ID BGSDebris{ 4840594 };
		inline constexpr REL::ID TESImageSpace{ 4840042 };
		inline constexpr REL::ID TESImageSpaceModifier{ 4839930 };
		inline constexpr REL::ID BGSListForm{ 4839946 };
		inline constexpr REL::ID BGSPerk{ 4839934 };
		inline constexpr REL::ID BGSBodyPartData{ 4842232 };
		inline constexpr REL::ID BGSCameraShot{ 4841860 };
		inline constexpr REL::ID BGSCameraPath{ 4841858 };
		inline constexpr REL::ID BGSVoiceType{ 4840284 };
		inline constexpr REL::ID BGSMaterialType{ 4841836 };
		inline constexpr REL::ID BGSImpactData{ 4841904 };
		inline constexpr REL::ID BGSImpactDataSet{ 4839908 };
		inline constexpr REL::ID BGSEncounterZone{ 4840050 };
		inline constexpr REL::ID BGSLocation{ 4840052 };
		inline constexpr REL::ID BGSMessage{ 4839780 };
		inline constexpr REL::ID BGSLightingTemplate{ 4841648 };
		inline constexpr REL::ID BGSMusicType{ 4840048 };
		inline constexpr REL::ID BGSFootstep{ 4841892 };
		inline constexpr REL::ID BGSFootstepSet{ 4841898 };
		inline constexpr REL::ID BGSDialogueBranch{ 4840060 };
		inline constexpr REL::ID BGSMusicTrackFormWrapper{ 4841970 };
		inline constexpr REL::ID TESWordOfPower{ 4842214 };
		inline constexpr REL::ID TESShout{ 4840682 };
		inline constexpr REL::ID BGSEquipSlot{ 4842262 };
		inline constexpr REL::ID BGSRelationship{ 4842312 };
		inline constexpr REL::ID BGSScene{ 4840072 };
		inline constexpr REL::ID BGSAssociationType{ 4842226 };
		inline constexpr REL::ID BGSOutfit{ 4841348 };
		inline constexpr REL::ID BGSMaterialObject{ 4841920 };
		inline constexpr REL::ID BGSMovementType{ 4842288 };
		inline constexpr REL::ID BGSSoundDescriptorForm{ 4841186 };
		inline constexpr REL::ID BGSSoundCategory{ 4840064 };





		// Add more AE-specific RTTI IDs here as needed
	}
}
