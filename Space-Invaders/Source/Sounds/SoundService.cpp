#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Sounds\SoundService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Config.h"

namespace Sound
{
	using namespace Global;

	void SoundService::initialize()
	{
		loadBackgroundMusicFromFile(); 
		loadSoundFromFile(); 
	}

	void SoundService::loadBackgroundMusicFromFile()
	{
		if (!background_music.openFromFile(Config::background_music_path)) //if this returns true then print error 
			printf("Error loading background music file");
	}

	void SoundService::loadSoundFromFile()
	{
		if (!buffer_button_click.loadFromFile(Config::button_click_sound_path)) 
			printf("Error loading background music file");
	}

	void SoundService::playSound(SoundType sound_type)
	{
		switch (sound_type)
		{
		case SoundType::BUTTON_CLICK:
			sound_effect.setBuffer(buffer_button_click);
			break;
		default:
			printf("Invalid sound type");
			return;
		}

		sound_effect.play();
	}

	void SoundService::playBackgroundMusic()
	{
		background_music.setLoop(true); 
		background_music.setVolume(background_music_volume); 
		background_music.play(); 
	}
}