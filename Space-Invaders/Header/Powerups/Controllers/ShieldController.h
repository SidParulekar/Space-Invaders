#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupController.h"

namespace Powerup
{
	namespace Controller
	{
		class ShieldController : public PowerupController
		{
		private:

		public:

			ShieldController(PowerupType type);
			virtual ~ShieldController();

			//void onCollected() override;
			void applyPowerup() override;

		};
	}
}