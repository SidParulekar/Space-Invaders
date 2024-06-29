#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyModel.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Elements\Bunker\BunkerController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Entities\EntityConfig.h"


namespace Enemy
{
	using namespace Global;
	using namespace Entity;
	using namespace Element::Bunker;

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
		updateFireTimer();
		processBulletFire();
		enemy_view->update();
		handleOutOfBounds();
	}

	void EnemyController::updateFireTimer()
	{
		elapsed_fire_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime(); //update the elapsed duration
	}

	void EnemyController::processBulletFire() //if elapsed duration is equal to or more than the amount of time we want to wait until firing than call the fire method.
	{
		if (elapsed_fire_duration >= rate_of_fire)
		{
			fireBullet();
			elapsed_fire_duration = 0.f; //set elapsed duration back to 0.
		}
	}

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

	const sf::Sprite& EnemyController::getColliderSprite()
	{
		return enemy_view->getEnemySprite();
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

	void EnemyController::onCollision(ICollider* other_collider)
	{
		//If enemy has collided with a bullet fired by player
		BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);
		if (bullet_controller && bullet_controller->getOwnerEntityType() != EntityType::ENEMY)
		{ 
			destroy();
			return;	
		}

		//If enemy has collided with a player
		PlayerController* player_controller = dynamic_cast<PlayerController*>(other_collider);
		if (player_controller)
		{ 
			destroy();
			return;	
		}

		//If enemy has collided with bunker
		BunkerController* bunker_controller = dynamic_cast<BunkerController*>(other_collider);
		if (bunker_controller) 
		{
			ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(getEnemyPosition(), 
				Animation::AnimationType::EXPLOSION);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::EXPLOSION);

			ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
			return;
		}
			
	}

	void EnemyController::destroy()
	{
		ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(getEnemyPosition(), 
			Animation::AnimationType::EXPLOSION);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::EXPLOSION);

		ServiceLocator::getInstance()->getPlayerService()->increaseEnemiesKilled(1);
		ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this); 	
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