#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Config.h"

namespace Powerup
{
	using namespace Global;

	PowerupView::PowerupView() 
	{ 

	}

	void PowerupView::initialize(PowerupController* controller)
	{
		powerup_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializePowerupSprite(powerup_controller->getPowerupType());
	}


	void PowerupView::initializePowerupSprite(PowerupType type)
	{
		switch (type)
		{
		case::Powerup::PowerupType::TRIPPLE_LASER:
			if (powerup_texture.loadFromFile(Config::tripple_laser_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scalePowerupSprite();
			}
			break;
		case::Powerup::PowerupType::SHIELD:
			if (powerup_texture.loadFromFile(Config::shield_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scalePowerupSprite();
			}
			break;
		case::Powerup::PowerupType::RAPID_FIRE:
			if (powerup_texture.loadFromFile(Config::rapid_fire_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scalePowerupSprite();
			}
			break;
		case::Powerup::PowerupType::OUTSCAL_BOMB:
			if (powerup_texture.loadFromFile(Config::outscal_bomb_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scalePowerupSprite();
			}
			break;
		}
	}

	void PowerupView::scalePowerupSprite()
	{
		powerup_sprite.setScale(
			static_cast<float>(powerup_sprite_width) / powerup_sprite.getTexture()->getSize().x,
			static_cast<float>(powerup_sprite_height) / powerup_sprite.getTexture()->getSize().y
		);
	}

	void PowerupView::update()
	{
		powerup_sprite.setPosition(powerup_controller->getCollectiblePosition());
	}

	void PowerupView::render()
	{
		game_window->draw(powerup_sprite);
	}

	PowerupView::~PowerupView() 
	{ 

	}
}
