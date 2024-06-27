#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupController.h"

namespace Powerup
{
	namespace Controller
	{
		class TripleLaserController : public PowerupController
		{
		private:

		public:

			TripleLaserController(PowerupType type);
			virtual ~TripleLaserController();

			//void onCollected() override;
			void applyPowerup() override;

		};
	}
}