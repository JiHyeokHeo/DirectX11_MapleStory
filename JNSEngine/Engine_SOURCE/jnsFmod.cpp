#include "jnsFmod.h"
#include <combaseapi.h>


namespace jns
{
	FMOD::Studio::System* Fmod::mSystem = nullptr;
	FMOD::System* Fmod::mCoreSystem = nullptr;

	void Fmod::Initialize()
	{
		void* extraDriverData = NULL;
		//CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
		//Common_Init();
		FMOD::Studio::System::create(&mSystem);

		// The example Studio project is authored for 5.1 sound, so set up the system output mode to match
		mSystem->getCoreSystem(&mCoreSystem);
		mCoreSystem->setSoftwareFormat(0, FMOD_SPEAKERMODE_5POINT1, 0);

		mSystem->initialize(1024, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, extraDriverData);

		//FMOD::Studio::Bank* masterBank = NULL;
		//FMOD::Sound* sound1;
		//FMOD_RESULT      result;
		//FMOD::Channel* channel1 = nullptr;
		////mSystem->load(Common_MediaPath("Master.bank"), FMOD_STUDIO_LOAD_BANK_NORMAL, &masterBank);
		//mCoreSystem->createSound("..\\Resources\\Sound\\smw_bonus_game_end.wav", FMOD_3D, 0, &sound1);
		//const float DISTANCEFACTOR = 1.0f;
		//result = sound1->set3DMinMaxDistance(0.5f * DISTANCEFACTOR, 5000.0f * DISTANCEFACTOR);
		//result = sound1->setMode(FMOD_LOOP_NORMAL);

		//FMOD_VECTOR pos = { 0.0f * DISTANCEFACTOR, 0.0f, 1.0f };
		//FMOD_VECTOR vel = { 0.0f, 0.0f, 0.0f };

		//result = mCoreSystem->playSound(sound1, 0, false, &channel1);
		//result = channel1->set3DAttributes(&pos, &vel);
		////result = channel1->setPaused(false);
		//
		//static float t = 0;
		//static FMOD_VECTOR lastpos = { 0.0f, 0.0f, 0.0f };
		//FMOD_VECTOR forward = { 0.0f, 0.0f, 1.0f };
		//FMOD_VECTOR up = { 0.0f, 1.0f, 0.0f };
		//FMOD_VECTOR vel2 = { 0.0f, 0.0f, 0.0f };;
		//FMOD_VECTOR listenerpos = { 0.0f, 0.0f, 0.0f };
		//result = mCoreSystem->set3DListenerAttributes(0, &listenerpos, &vel2, &forward, &up);

		//mCoreSystem->update();
	}

	bool Fmod::CreateSound(const std::string& path, FMOD::Sound** sound)
	{
		if (FMOD_OK != mCoreSystem->createSound(path.c_str(), FMOD_3D, 0, sound))
			return false;

		return true;
	}

	void Fmod::SoundPlay(FMOD::Sound* sound, FMOD::Channel** channel)
	{
		mCoreSystem->playSound(sound, 0, false, channel);
	}

	void Fmod::Set3DListenerAttributes(const Vector3* pos, const Vector3* vel, const Vector3* forward, const Vector3* up)
	{
		FMOD_VECTOR fmodPos(pos->x, pos->y, pos->z);
		FMOD_VECTOR fmodVel(vel->x, vel->y, vel->z);
		FMOD_VECTOR fmodForward(forward->x, forward->y, forward->z);
		FMOD_VECTOR fmodUp(up->x, up->y, up->z);

		mCoreSystem->set3DListenerAttributes(0, &fmodPos, &fmodVel, &fmodForward, &fmodUp);
	}

	void Fmod::Release()
	{
		//mCoreSystem->release();
		//mCoreSystem = nullptr;

		mSystem->release();
		mSystem = nullptr;
	}


}
