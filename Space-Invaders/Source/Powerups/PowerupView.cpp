#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Config.h"

namespace Powerup
{
	using namespace Global;

	using namespace UI::UIElement;

	PowerupView::PowerupView() 
	{ 
		createPowerupImage(); 
	}

	void PowerupView::createPowerupImage()
	{
		powerup_image = new ImageView();
	}

	void PowerupView::initialize(PowerupController* controller)
	{
		powerup_controller = controller;
		initializePowerupImage();
	}

	void PowerupView::initializePowerupImage()
	{
		powerup_image->initialize(getPowerupTexturePath(), powerup_sprite_width, powerup_sprite_height, powerup_controller->getCollectiblePosition()); 
	}

	sf::String PowerupView::getPowerupTexturePath()
	{
		switch (powerup_controller->getPowerupType())
		{
		case::Powerup::PowerupType::SHIELD:
			return Config::shield_texture_path;

		case::Powerup::PowerupType::TRIPPLE_LASER:
			return Config::tripple_laser_texture_path;

		case::Powerup::PowerupType::RAPID_FIRE:
			return Config::rapid_fire_texture_path;

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return Config::outscal_bomb_texture_path;
		}
	}

	void PowerupView::update()
	{
		powerup_image->setPosition(powerup_controller->getCollectiblePosition());
		powerup_image->update();
	}

	void PowerupView::render()
	{
		powerup_image->render();
	}

	const sf::Sprite& PowerupView::getPowerupSprite()
	{
		powerup_image->getImageSprite();
	}

	PowerupView::~PowerupView() 
	{ 
		destroy();
	}

	void PowerupView::destroy()
	{
		delete powerup_image;
	}


}
