#pragma once
#include "jnsComponent.h"
#include "jnsAudioClip.h"

namespace jns
{
	class AudioSource : public Component
	{
	public:
		AudioSource();
		~AudioSource();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void Play();
		void Stop();
		void SetLoop(bool loop);
		void SetVolume(float vol);
		void SetMute(bool mute);

		void SetClip(std::shared_ptr<AudioClip> clip) { mAudioClip = clip; }
		std::shared_ptr<AudioClip> GetClip() { return mAudioClip; }

	private:
		std::shared_ptr<AudioClip> mAudioClip;
	};
}