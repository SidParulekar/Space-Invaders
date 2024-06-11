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

			void move() override; 
			void moveDown();

		public:

			SubZeroController(EnemyType type);
			~SubZeroController();

			void initialize() override;
		};
	}	
}
