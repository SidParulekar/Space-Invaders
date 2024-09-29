#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"

namespace Enemy
{
	namespace Controllers
	{
		class ThunderSnakeController: public EnemyController
		{
        private:
            float vertical_travel_distance = 50.f;

            void move() override;
            void moveLeft();
            void moveRight();       

            void fireBullet() override;

        public:
            ThunderSnakeController(EnemyType type);
            ~ThunderSnakeController();

            void initialize() override;
		};
	}
}