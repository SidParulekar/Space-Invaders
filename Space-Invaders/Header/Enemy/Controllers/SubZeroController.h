#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"

namespace Enemy
{
	namespace Controllers
	{
		enum class EnemyType;

		class SubZeroController : public EnemyController
		{
		private:
			float vertical_movement_speed = 100.0f;
			EnemyModel* enemy_model;

			void move() override; 
			void moveDown();

		public:

			SubZeroController(EnemyType type);
			~SubZeroController();

			void initialize() override;
		};
	}	
}
