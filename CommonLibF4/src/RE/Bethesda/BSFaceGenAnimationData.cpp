#include "C:/cpp/CommonLibF4/build/CommonLibF4/CMakeFiles/CommonLibF4.dir/Release/cmake_pch.hxx"
#include "RE/Bethesda/BSFaceGenAnimationData.h"

namespace RE
{
	BSFaceGenAnimationData::~BSFaceGenAnimationData() {}

	NiExtraData* BSFaceGenAnimationData::CreateClone()
	{
		using func_t = decltype(&BSFaceGenAnimationData::CreateClone);
		REL::Relocation<func_t> func{ REL::Offset(0x667E20) };
		return func(this);
	}

	void BSFaceGenAnimationData::UpdateMorphsFromLip(float a_delta)
	{
		using func_t = decltype(&BSFaceGenAnimationData::UpdateMorphsFromLip);
		REL::Relocation<func_t> func{ REL::Offset(0x667E50) };
		return func(this, a_delta);
	}

	void BSFaceGenAnimationData::ReleaseLipHandleIfFinished()
	{
		using func_t = decltype(&BSFaceGenAnimationData::ReleaseLipHandleIfFinished);
		REL::Relocation<func_t> func{ REL::Offset(0x668040) };
		return func(this);
	}

	void BSFaceGenAnimationData::UpdateBlinking(float a_delta)
	{
		using func_t = decltype(&BSFaceGenAnimationData::UpdateBlinking);
		REL::Relocation<func_t> func{ REL::Offset(0x668170) };
		return func(this, a_delta);
	}

	void BSFaceGenAnimationData::BlinkEyes(float a_delta)
	{
		using func_t = decltype(&BSFaceGenAnimationData::BlinkEyes);
		REL::Relocation<func_t> func{ REL::Offset(0x6683C0) };
		return func(this, a_delta);
	}

	void BSFaceGenAnimationData::InitSDM()
	{
		using func_t = decltype(&BSFaceGenAnimationData::InitSDM);
		REL::Relocation<func_t> func{ REL::Offset(0x6686F0) };
		return func();
	}

	void BSFaceGenAnimationData::KillSDM()
	{
		using func_t = decltype(&BSFaceGenAnimationData::KillSDM);
		REL::Relocation<func_t> func{ REL::Offset(0x668760) };
		return func();
	}

	float BSFaceGenAnimationData::GetSpeechDelay()
	{
		using func_t = decltype(&BSFaceGenAnimationData::GetSpeechDelay);
		REL::Relocation<func_t> func{ REL::Offset(0x668770) };
		return func(this);
	}

	void BSFaceGenAnimationData::ResetCurrentMorphs(float a_delta)
	{
		using func_t = decltype(&BSFaceGenAnimationData::ResetCurrentMorphs);
		REL::Relocation<func_t> func{ REL::Offset(0x668780) };
		return func(this, a_delta);
	}

	void BSFaceGenAnimationData::ResetCurrentMorphsForDeath(float a_delta)
	{
		using func_t = decltype(&BSFaceGenAnimationData::ResetCurrentMorphsForDeath);
		REL::Relocation<func_t> func{ REL::Offset(0x668800) };
		return func(this, a_delta);
	}

	void BSFaceGenAnimationData::SetDead(bool a_dead)
	{
		using func_t = decltype(&BSFaceGenAnimationData::SetDead);
		REL::Relocation<func_t> func{ REL::Offset(0x668840) };
		return func(this, a_dead);
	}

	void BSFaceGenAnimationData::SetLidsToFollowEyes(float a_delta)
	{
		using func_t = decltype(&BSFaceGenAnimationData::SetLidsToFollowEyes);
		REL::Relocation<func_t> func{ REL::Offset(0x6689A0) };
		return func(this, a_delta);
	}

	void BSFaceGenAnimationData::Update(float a_delta, bool a_force)
	{
		using func_t = decltype(&BSFaceGenAnimationData::Update);
		REL::Relocation<func_t> func{ REL::Offset(0x6689D0) };
		return func(this, a_delta, a_force);
	}

	void BSFaceGenAnimationData::CopyDataForCharGen(BSFaceGenAnimationData* a_src)
	{
		using func_t = decltype(&BSFaceGenAnimationData::CopyDataForCharGen);
		REL::Relocation<func_t> func{ REL::Offset(0x668DA0) };
		return func(this, a_src);
	}

	void BSFaceGenAnimationData::SetLipSynchAnimResource(void* a_handle)
	{
		using func_t = decltype(&BSFaceGenAnimationData::SetLipSynchAnimResource);
		REL::Relocation<func_t> func{ REL::Offset(0x668E70) };
		return func(this, a_handle);
	}

	const char* BSFaceGenAnimationData::GetBlinkStateString()
	{
		using func_t = decltype(&BSFaceGenAnimationData::GetBlinkStateString);
		REL::Relocation<func_t> func{ REL::Offset(0x668F30) };
		return func(this);
	}
}
