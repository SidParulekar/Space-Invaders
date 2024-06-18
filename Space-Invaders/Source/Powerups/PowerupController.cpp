#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupModel.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	
	PowerupController::PowerupController(PowerupType type)
	{
		powerup_view = new PowerupView();
		powerup_model = new PowerupModel(type);
	}
	
	void PowerupController::initialize(sf::Vector2f position)
	{
		powerup_view->initialize(this);
		powerup_model->initialize(position);
	}
	void PowerupController::update()
	{
		updatePowerupPosition();
		powerup_view->update();
		handleOutOfBounds();
	}

	void PowerupController::updatePowerupPosition()
	{
		sf::Vector2f currentPosition = powerup_model->getPowerupPosition();
		currentPosition.y += powerup_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		powerup_model->setPowerupPosition(currentPosition);
	}

	void PowerupController::handleOutOfBounds()
	{
		sf::Vector2f powerupPosition = getCollectiblePosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (powerupPosition.x < 0 || powerupPosition.x > windowSize.x ||
			powerupPosition.y < 0 || powerupPosition.y > windowSize.y)
		{
			ServiceLocator::getInstance()->getPowerupService()->destroyPowerup(this);
		}
	}

	void PowerupController::render()
	{
		powerup_view->render();
	}

	void PowerupController::onCollected()
	{
	}

	sf::Vector2f PowerupController::getCollectiblePosition()
	{
		return powerup_model->getPowerupPosition();
	}

	PowerupType PowerupController::getPowerupType()
	{
		return powerup_model->getPowerupType();
	}

	PowerupController::~PowerupController()
	{
		delete powerup_view;
		delete powerup_model;
	}
}