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
		
		/*void OutscalBombController::onCollected()
		{
		}*/

		void OutscalBombController::applyPowerup()
		{
			current_enemies = ServiceLocator::getInstance()->getEnemyService()->getCurrentEnemies();
			ServiceLocator::getInstance()->getPlayerService()->increaseEnemiesKilled(current_enemies);
			ServiceLocator::getInstance()->getEnemyService()->bombDestroy();
		}

		OutscalBombController::~OutscalBombController()
		{
		}

		
	}
}