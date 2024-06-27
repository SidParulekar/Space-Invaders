#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\Controllers\ShieldController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	namespace Controller
	{
		ShieldController::ShieldController(PowerupType type) :PowerupController(type)
		{
		}

		/*void ShieldController::onCollected()
		{
		}*/

		void ShieldController::applyPowerup()
		{
			ServiceLocator::getInstance()->getPlayerService()->enableShield();
		}

		ShieldController::~ShieldController()
		{
		}
	}
}