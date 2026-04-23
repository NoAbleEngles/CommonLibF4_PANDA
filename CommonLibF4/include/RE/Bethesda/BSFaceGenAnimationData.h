#pragma once

#include "RE/NetImmerse/NiExtraData.h"
#include "RE/Bethesda/BSFixedString.h"

namespace RE
{
	template <class T>
	class BSResource_RHandleType;
	struct FaceEmotionalIdles;

	class __declspec(novtable) BSFaceGenAnimationData :
		public NiExtraData  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSFaceGenAnimationData };
		static constexpr auto VTABLE{ VTABLE::BSFaceGenAnimationData };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSFaceGenAnimationData };

		BSFaceGenAnimationData();
		virtual ~BSFaceGenAnimationData();

		// override (NiExtraData)
		virtual NiExtraData* CreateClone() override;                                                       // 26

		// Methods from disassembly analysis
		void UpdateMorphsFromLip(float a_delta);
		void ReleaseLipHandleIfFinished();
		void UpdateBlinking(float a_delta);
		void BlinkEyes(float a_delta);
		static void InitSDM();
		static void KillSDM();
		float GetSpeechDelay();
		void ResetCurrentMorphs(float a_delta);
		void ResetCurrentMorphsForDeath(float a_delta);
		void SetDead(bool a_dead);
		void SetLidsToFollowEyes(float a_delta);
		void Update(float a_delta, bool a_force);
		void CopyDataForCharGen(BSFaceGenAnimationData* a_src);
		void SetLipSynchAnimResource(void* a_handle);  // BSResource::RHandleType<...>
		const char* GetBlinkStateString();

		F4_HEAP_REDEFINE_ALIGNED_NEW(BSFaceGenAnimationData);

		// members (from constructor analysis) - base NiExtraData is 0x18
		std::uint8_t morphData1[0xD8];                               // 018 - first morph data array
		std::uint8_t morphData2[0xD8];                               // 0F0 - second morph data array  
		std::uint8_t morphData3[0xD8];                               // 1C8 - third morph data array
		std::uint32_t flags;                                         // 2A0
		std::uint32_t instanceData;                                  // 2A4 - FaceEmotionalIdles::InstanceData (simplified)
		std::uint32_t field2A8;                                      // 2A8
		float blinkTimer;                                            // 2AC - random blink timer
		void* field2B0;                                              // 2B0
		void* field2B8;                                              // 2B8
		void* lipSynchHandle;                                        // 2C0 - LipSynch resource handle
		std::uint32_t field2C8;                                      // 2C8
		std::uint16_t field2CC;                                      // 2CC
		std::uint16_t pad2CE;                                        // 2CE
		BSFixedString currentState;                                  // 2D0 - current facial state (8 bytes)
		void* field2D8;                                              // 2D8
		std::uint32_t blinkState;                                    // 2E0 - initialized to 3
		std::uint32_t pad2E4;                                        // 2E4
	};
	static_assert(sizeof(BSFaceGenAnimationData) == 0x2E8);
}
