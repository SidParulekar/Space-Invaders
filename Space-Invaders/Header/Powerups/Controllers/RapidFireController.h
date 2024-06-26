#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupController.h"

namespace Powerup
{
	namespace Controller
	{
		class RapidFireController : public PowerupController
		{
		private:

		public:

			RapidFireController(PowerupType type);
			virtual ~RapidFireController();

			void onCollected() override;
			//void applyPowerup() override;

		};
	}
}