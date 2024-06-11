#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyModel.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController(EnemyType type)
	{
		enemy_model = new EnemyModel(type); 
		enemy_view = new EnemyView();
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_model->setEnemyPosition(getRandomInitialPosition());
		enemy_view->initialize(this);
	}

	void EnemyController::update()
	{
		move();
		enemy_view->update();
		handleOutOfBounds();
	}

	/*void EnemyController::move()
	{
		switch (enemy_model->getMovementDirection())
		{
		case::Enemy::MovementDirection::LEFT:
			moveLeft();
			break;

		case::Enemy::MovementDirection::RIGHT:
			moveRight();
			break;

		case::Enemy::MovementDirection::DOWN:
			moveDown();
			break;
		}
	}

	void EnemyController::moveLeft()
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

	void EnemyController::moveRight()
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

	void EnemyController::moveDown()
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
	}*/

	sf::Vector2f EnemyController::getRandomInitialPosition()
	{
		// Calculate distance between left most position and a random position between left most and right most
		float x_offset_distance = (std::rand() % static_cast<int>(enemy_model->right_most_position.x - enemy_model->left_most_position.x));

		// Add the calculated distance to left most position to get starting position of enemy
		float x_position = enemy_model->left_most_position.x + x_offset_distance;

		// The y position remains the same.
		float y_position = enemy_model->left_most_position.y;

		return sf::Vector2f(x_position, y_position);
	}

	void EnemyController::handleOutOfBounds()
	{
		sf::Vector2f enemyPosition = getEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		// Destroy the enemy if it goes out of bounds.
		if (enemyPosition.x < 0 || enemyPosition.x > windowSize.x ||
			enemyPosition.y < 0 || enemyPosition.y > windowSize.y)
		{
			ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
		}
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}

	EnemyType EnemyController::getEnemyType()
	{
		return enemy_model->getEnemyType();
	}

	EnemyState EnemyController::getEnemyState()
	{
		return enemy_model->getEnemyState();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	EnemyController::~EnemyController()
	{
		delete enemy_model;
		delete enemy_view;
		enemy_model = nullptr;
		enemy_view = nullptr;
	}
}