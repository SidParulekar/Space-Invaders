#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\Controllers\RapidFireController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	namespace Controller
	{
		RapidFireController::RapidFireController(PowerupType type) :PowerupController(type)
		{
		}

		void RapidFireController::onCollected()
		{
		}

		/*void RapidFireController::applyPowerup()
		{
			ServiceLocator::getInstance()->getPlayerService()->enableRapidFire();
		}*/

		RapidFireController::~RapidFireController()
		{
		}	
	}
}