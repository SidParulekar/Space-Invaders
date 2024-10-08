#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"

namespace Enemy
{
	namespace Controllers
	{
		class ZapperController : public EnemyController
		{
        private:
            float vertical_travel_distance = 100.f;     

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDown();

            void fireBullet() override;

        public:
            ZapperController(EnemyType type); 
            ~ZapperController();

            void initialize() override;
		};
	}	
}
