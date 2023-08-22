#include "jnsAudioSource.h"
#include "jnsAudioClip.h"
#include "jnsTransform.h"
#include "jnsGameObject.h"

namespace jns
{
	AudioSource::AudioSource()
		: Component(eComponentType::AudioSource)
		, mAudioClip(nullptr)
	{

	}

	AudioSource::~AudioSource()
	{

	}

	void AudioSource::Initialize()
	{
	}

	void AudioSource::Update()
	{
	}

	void AudioSource::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Vector3 foward = tr->Foward();

		//mAudioClip->Set3DAttributes(pos, foward);
	}

	void AudioSource::Render()
	{
	}

	void AudioSource::Play()
	{
		if (mAudioClip != nullptr)
			mAudioClip->Play();
	}
	void AudioSource::Stop()
	{
		if(mAudioClip != nullptr)
			mAudioClip->Stop();
	}
	void AudioSource::SetLoop(bool loop)
	{
		if (mAudioClip != nullptr)
			mAudioClip->SetLoop(loop);
	}
	void AudioSource::SetVolume(float vol)
	{
		if (mAudioClip != nullptr)
			mAudioClip->SetVolume(vol);
	}
	void AudioSource::SetMute(bool mute)
	{
		if (mAudioClip != nullptr)
			mAudioClip->SetMute(mute);
	}
}