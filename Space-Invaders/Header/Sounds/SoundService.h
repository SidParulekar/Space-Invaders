#pragma once
#include <SFML/Audio.hpp>
namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
		FIRE_BULLET
	};

	class SoundService
	{
	private:
		const int background_music_volume = 30;

		sf::Music background_music;
		sf::Sound sound_effect;
		sf::SoundBuffer buffer_button_click;
		sf::SoundBuffer buffer_fire_bullet;

		void loadBackgroundMusicFromFile();
		void loadSoundFromFile();
	public:
		void initialize();

		void playSound(SoundType);
		void playBackgroundMusic();
	};

}
