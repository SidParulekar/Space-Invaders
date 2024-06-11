#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"

namespace Enemy
{
	namespace Controllers
	{
        enum class EnemyType;

		class ZapperController : public EnemyController
		{
        private:
            float vertical_travel_distance = 100.f;

            EnemyModel* enemy_model;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDown();

        public:
            ZapperController(EnemyType type); 
            ~ZapperController();

            void initialize() override;
		};
	}	
}
