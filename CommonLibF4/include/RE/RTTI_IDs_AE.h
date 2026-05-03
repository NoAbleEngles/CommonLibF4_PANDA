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
		inline constexpr REL::ID BGSSoundOutput{ 4840062 };
		inline constexpr REL::ID BGSCollisionLayer{ 4841360 };
		inline constexpr REL::ID BGSColorForm{ 4841148 };
		inline constexpr REL::ID BGSReverbParameters{ 4841854 };
		inline constexpr REL::ID BGSPackIn{ 4841354 };
		inline constexpr REL::ID BGSAimModel{ 4841280 };
		inline constexpr REL::ID BGSConstructibleObject{ 4841302 };
		inline constexpr REL::ID BGSMaterialSwap{ 4839802 };
		inline constexpr REL::ID BGSZoomData{ 4841400 };
		inline constexpr REL::ID BGSInstanceNamingRules{ 4841244 };
		inline constexpr REL::ID BGSSoundKeywordMapping{ 4841260 };
		inline constexpr REL::ID BGSAudioEffectChain{ 4841196 };
		inline constexpr REL::ID BGSAttractionRule{ 4841146 };
		inline constexpr REL::ID BGSSoundCategorySnapshot{ 4841254 };
		inline constexpr REL::ID BGSSoundTagSet{ 4839816 };
		inline constexpr REL::ID BSLensFlareRenderData{ 4841326 };
		inline constexpr REL::ID BGSLensFlare{ 4841324 };
		inline constexpr REL::ID BGSGodRays{ 4840076 };
		
		//ActorValueInfo
		inline constexpr REL::ID ActorValueInfo{ 24839932 };

		//Archive2
		inline constexpr REL::ID BSResource__Archive2__Index{ 4858801 };
		inline constexpr REL::ID BSResource__Archive2__ReaderStream{ 4858797 };
		inline constexpr REL::ID BSResource__Archive2__AsyncReaderStream{ 4858807 };

		// BGSBaseAliases
		inline constexpr REL::ID ExtraReferenceHandles{ 4840188 };
		inline constexpr REL::ID BGSRefAlias{ 4841170 };

		// BGSCharacterTint
		inline constexpr REL::ID BGSCharacterTint__Template__Entry{ 4841156 };
		inline constexpr REL::ID BGSCharacterTint__Template__Mask{ 4841158 };
		inline constexpr REL::ID BGSCharacterTint__Template__Palette{ 4841160 };
		inline constexpr REL::ID BGSCharacterTint__Template__TextureSet{ 4841164 };
		inline constexpr REL::ID BGSCharacterTint__Entry{ 4841150 };
		inline constexpr REL::ID BGSCharacterTint__MaskEntry{ 4841152 };
		inline constexpr REL::ID BGSCharacterTint__PaletteEntry{ 4841154 };
		inline constexpr REL::ID BGSCharacterTint__TextureSetEntry{ 4841162 };

		// BGSDefaultObjectManager
		inline constexpr REL::ID BGSDefaultObjectManager{ 4841884 };
		inline constexpr REL::ID BGSDefaultObject{ 4841238 };

		// BGSHeadPart
		inline constexpr REL::ID BGSHeadPart{ 4842268 };

		// BGSInventoryItem
		inline constexpr REL::ID BGSInventoryItem__Stack{ 4840784 };
		inline constexpr REL::ID BGSInventoryItem__StackDataCompareFunctor{ 4840770 };
		inline constexpr REL::ID BGSInventoryItem__CheckStackIDFunctor{ 4840772 };
		inline constexpr REL::ID BGSInventoryItem__StackDataWriteFunctor{ 4840776 };
		inline constexpr auto BGSInventoryItem__ModifyModDataFunctor{ 0x3758a50 };
		inline constexpr REL::ID __ApplyChangesFunctor{ 4847168 };

		//BGSMod
		inline constexpr REL::ID BGSMod__Container{ 4839796 };
		inline constexpr REL::ID BGSMod__Attachment__Mod{ 4839788 };
		inline constexpr REL::ID BGSMod__Template__Item{ 4839794 };
		inline constexpr REL::ID BGSMod__Template__Items{ 4839790 };

		//BGSPrimitive
		inline constexpr REL::ID BGSPrimitive{ 4840836 };

		//BGSStoryManagerTreeVisitor
		inline constexpr REL::ID BGSStoryManagerTreeVisitor{ 4844060 };
		inline constexpr REL::ID BGSStoryManagerTreeForm{ 4840556 };
		inline constexpr REL::ID TESQuest{ 4840074 };
		inline constexpr REL::ID BGSStoryManagerNodeBase{ 4840554 };
		inline constexpr REL::ID BGSStoryManagerBranchNode{ 4840552 };
		inline constexpr REL::ID BGSStoryManagerQuestNode{ 4844082 };
		inline constexpr REL::ID BGSStoryManagerEventNode{ 4844076 };

		//BGSTextureSet
		inline constexpr REL::ID BGSTextureSet{ 4841294 };

		//bhkCharacterController
		inline constexpr REL::ID bhkNPCollisionObjectBase{ 4859769 };
		inline constexpr REL::ID bhkNPCollisionObject{ 4859767 };
		inline constexpr REL::ID bhkNPCollisionObjectUnlinked{ 4859771 };
		inline constexpr REL::ID bhkCharacterController{ 4859801 };
	}
}
