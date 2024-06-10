#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"

namespace Enemy
{
	namespace Controllers
	{
		class SubZeroController : public EnemyController
		{
		private:
			float movement_speed = 100.0f;

			void move() override; 
			void moveDown();

		public:

			SubZeroController();
			~SubZeroController();

			void initialize() override;
		};
	}	
}
