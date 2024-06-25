#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\Controllers\UFOController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyModel.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Entities\EntityConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Entity;
	using namespace Bullet;

	namespace Controllers
	{

		UFOController::UFOController(EnemyType type) : EnemyController(type)
		{

		}

		void UFOController::initialize()
		{
			EnemyController::initialize();
		}

		void UFOController::onCollision(ICollider* other_collider) 
		{
			EnemyController::onCollision(other_collider);

			//If UFO has collided with a bullet fired by player
			BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);

			if (bullet_controller && bullet_controller->getOwnerEntityType() != EntityType::ENEMY)
			{
				ServiceLocator::getInstance()->getPowerupService()->spawnPowerup(getRandomPowerupType(), enemy_model->getEnemyPosition());
				return;
			}
		}

		void UFOController::move()
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

		void UFOController::moveLeft()
		{
			// Enemy moves left
			sf::Vector2f currentPosition = getEnemyPosition();
			currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			// If enemy has reached left most position then start moving right
			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT); 
				enemy_model->setReferencePosition(currentPosition);
			}

			// Else enemy keeps moving left
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void UFOController::moveRight()
		{
			// Enemy moves right
			sf::Vector2f currentPosition = getEnemyPosition();
			currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			// If enemy has reached right most position then start moving left
			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
				enemy_model->setReferencePosition(currentPosition);
			}

			// Else enemy keeps moving right
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void UFOController::fireBullet()
		{
		}

		Powerup::PowerupType UFOController::getRandomPowerupType()
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
			return static_cast<Powerup::PowerupType>(random_value);
		}

		UFOController::~UFOController()
		{
		}


	}
}