#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"

namespace Enemy
{
	namespace Controllers
	{
		class ThunderSnakeController: public EnemyController
		{
        private:
            float vertical_travel_distance = 100.f;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDown();

            void fireBullet() override;

        public:
            ThunderSnakeController(EnemyType type);
            ~ThunderSnakeController();

            void initialize() override;
		};
	}
}