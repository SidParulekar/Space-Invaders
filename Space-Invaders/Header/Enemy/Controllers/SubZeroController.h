#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"

namespace Enemy
{
	namespace Controllers
	{
		class SubZeroController : public EnemyController
		{
		private:
			float vertical_movement_speed = 100.0f;

			float subzero_rate_of_fire = 5.f;

			void move() override; 
			void moveDown();

			void fireBullet() override;

		public:

			SubZeroController(EnemyType type);
			~SubZeroController();

			void initialize() override;
		};
	}	
}
