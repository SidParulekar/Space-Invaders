#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupConfig.h"

namespace Enemy
{
    namespace Controllers
    {
        class UFOController : public EnemyController
        {
        private:
           
            void move() override;
            void moveLeft();
            void moveRight();

            void fireBullet() override;

            Powerup::PowerupType getRandomPowerupType(); 

        public:
            UFOController(EnemyType type);
            ~UFOController();

            void initialize() override;

            void onCollision(ICollider* other_collider) override;
        };
    }
}