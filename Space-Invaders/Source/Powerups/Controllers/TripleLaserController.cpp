#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\Controllers\TripleLaserController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	namespace Controller
	{
		TripleLaserController::TripleLaserController(PowerupType type) :PowerupController(type)
		{
		}

		/*void TripleLaserController::onCollected()
		{
		}*/

		void TripleLaserController::applyPowerup()
		{
			ServiceLocator::getInstance()->getPlayerService()->enableTripleLaser();
		}

		TripleLaserController::~TripleLaserController()
		{
		}
	}
}