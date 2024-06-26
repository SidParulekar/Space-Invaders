#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\Controllers\SubZeroController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyModel.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Entities\EntityConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Entities\EntityConfig.h"


namespace Enemy
{
	using namespace Global;
	using namespace Entity;

	namespace Controllers
	{
		SubZeroController::SubZeroController(EnemyType type) : EnemyController(type) 
		{

		}

		void SubZeroController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			rate_of_fire = subzero_rate_of_fire;
		}

		void SubZeroController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void SubZeroController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemy_model->setEnemyPosition(currentPosition);
		}

		void SubZeroController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::FROST_BULLET,
				enemy_model->getEnemyPosition() + enemy_model->bullet_position_offset,
				Bullet::MovementDirection::DOWN, Entity::EntityType::ENEMY); 

		}


		SubZeroController::~SubZeroController()
		{
		}

		
	}
}


