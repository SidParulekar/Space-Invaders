#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\Controllers\ZapperController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyModel.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	namespace Controllers
	{
		void ZapperController::move()
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

				// If the movement direction is DOWN
			case::Enemy::MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void ZapperController::moveLeft()
		{
			// Enemy moves left
			sf::Vector2f currentPosition = getEnemyPosition();
			currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			// If enemy has reached left most position then start moving down
			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}

			// Else enemy keeps moving left
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ZapperController::moveRight()
		{
			// Enemy moves right
			sf::Vector2f currentPosition = getEnemyPosition();
			currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			// If enemy has reached right most position then start moving down
			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}

			// Else enemy keeps moving right
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ZapperController::moveDown()
		{
			// Enemy moves down
			sf::Vector2f currentPosition = getEnemyPosition();
			currentPosition.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			// If enemy has moved down by defined amount then enemy starts to move horizontally
			if (currentPosition.y >= enemy_model->getReferencePosition().y + enemy_model->vertical_travel_distance)
			{
				// If enemy had moved down from left most position then enemy starts to move right
				if (enemy_model->getReferencePosition().x <= enemy_model->left_most_position.x)
				{
					enemy_model->setMovementDirection(MovementDirection::RIGHT);
				}

				// Else enemy moves left
				else enemy_model->setMovementDirection(MovementDirection::LEFT);
			}

			// Else enemy keeps moving down
			else enemy_model->setEnemyPosition(currentPosition);
		}

		ZapperController::ZapperController(EnemyType type)
		{
		}

		ZapperController::~ZapperController()
		{
		}

		void ZapperController::initialize()
		{
			EnemyController::initialize();
		}
	}
}



