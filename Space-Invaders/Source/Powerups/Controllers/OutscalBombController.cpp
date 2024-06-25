#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\Controllers\OutscalBombController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	namespace Controller
	{
		OutscalBombController::OutscalBombController(PowerupType type):PowerupController(type)
		{
		}
		
		void OutscalBombController::onCollected()
		{
		}

		void OutscalBombController::applyPowerup()
		{
			ServiceLocator::getInstance()->getEnemyService()->reset();
		}

		OutscalBombController::~OutscalBombController()
		{
		}

		
	}
}