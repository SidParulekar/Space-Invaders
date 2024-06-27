#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupController.h"

namespace Powerup
{
	namespace Controller
	{
		class OutscalBombController: public PowerupController
		{
		private:

		public:

			int current_enemies;

			OutscalBombController(PowerupType type);
			virtual ~OutscalBombController();

			//void onCollected() override;
			void applyPowerup() override;

		};
	}
}