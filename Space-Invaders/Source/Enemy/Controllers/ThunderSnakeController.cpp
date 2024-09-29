#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\Controllers\ThunderSnakeController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyModel.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyConfig.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Entities\EntityConfig.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Enemy
{
	using namespace Global;
	using namespace Entity;

	namespace Controllers
	{

		ThunderSnakeController::ThunderSnakeController(EnemyType type) : EnemyController(type)
		{

		}

		void ThunderSnakeController::initialize()
		{
			EnemyController::initialize();
		}

		void ThunderSnakeController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
				// If the movement direction is LEFT
			case::Enemy::MovementDirection::LEFT:
				moveLeft();
				break;

				// If the movement direction is RIGHT
			case::Enemy::MovementDirection::RIGHT:
				moveRight();
				break;
			
			}
		}

		void ThunderSnakeController::moveLeft()
		{
			// Enemy moves diagonally left
			sf::Vector2f currentPosition = getEnemyPosition();
			currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.y += vertical_travel_distance * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			// If enemy has reached left most position then start moving diagonally right
			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
				enemy_model->setReferencePosition(currentPosition);
			}

			// Else enemy keeps moving diagonally left
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ThunderSnakeController::moveRight()
		{
			// Enemy moves diagonally right
			sf::Vector2f currentPosition = getEnemyPosition();
			currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.y += vertical_travel_distance * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			// If enemy has reached right most position then start moving diagonally left
			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
				enemy_model->setReferencePosition(currentPosition);
			}

			// Else enemy keeps moving diagonally right
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ThunderSnakeController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::TORPEDO,
				enemy_model->getEnemyPosition() + enemy_model->bullet_position_offset,
				Bullet::MovementDirection::DOWN, Entity::EntityType::ENEMY);

		}


		ThunderSnakeController::~ThunderSnakeController() 
		{
		}


	}
}
