#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\Controllers\SubZeroController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\Controllers\ZapperController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\Controllers\UFOController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\Controllers\ThunderSnakeController.h" 
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Collisions\ICollider.h"

namespace Enemy
{
	using namespace Global;

	Enemy::EnemyService::EnemyService()
	{
		// To get random initial seed value so that new sequence of numbers is generated for each game run
		std::srand(static_cast<unsigned>(std::time(nullptr))); 
	}

	void Enemy::EnemyService::initialize()
	{
		spawn_timer = spawn_interval;	
	}

	void Enemy::EnemyService::update()
	{
		updateSpawnTimer(); 
		processEnemySpawn(); 

		for (int i = 0; i < enemy_list.size(); i++) enemy_list[i]->update(); 

		destroyFlaggedEnemies();
	}

	void EnemyService::updateSpawnTimer()
	{
		spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyService::processEnemySpawn()
	{
		if (spawn_timer >= spawn_interval)
		{
			spawnEnemy();
			spawn_timer = 0.0f;
		}
	}


	EnemyController* EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType());

		enemy_controller->initialize();

		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(enemy_controller));
		enemy_list.push_back(enemy_controller);

		return enemy_controller;
	}

	EnemyType EnemyService::getRandomEnemyType()
	{
		int randomType = std::rand() % 4;
		return static_cast<Enemy::EnemyType>(randomType);
	}

	EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
	{
		switch (enemy_type)
		{
		case::Enemy::EnemyType::ZAPPER:
			return new Controllers::ZapperController(enemy_type); 

		case::Enemy::EnemyType::THUNDER_SNAKE:
			return new Controllers::ThunderSnakeController(enemy_type);

		case::Enemy::EnemyType::SUBZERO:
			return new Controllers::SubZeroController(enemy_type);

		case::Enemy::EnemyType::UFO: 
			return new Controllers::UFOController(enemy_type);

		
		}
	}

	void Enemy::EnemyService::render()
	{
		for (int i = 0; i < enemy_list.size(); i++) enemy_list[i]->render();
	}

	int EnemyService::getCurrentEnemies()
	{
		return enemy_list.size();
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		dynamic_cast<ICollider*>(enemy_controller)->disableCollision();
		flagged_enemy_list.push_back(enemy_controller);
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
	}

	void EnemyService::bombDestroy()
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(enemy_list[i]->getEnemyPosition(),
				Animation::AnimationType::EXPLOSION);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::EXPLOSION);
			destroyEnemy(enemy_list[i]);
		}
		enemy_list.clear();

		spawn_timer = 0.0f;
	}

	void EnemyService::destroyFlaggedEnemies()
	{
		for (int i = 0; i < flagged_enemy_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_enemy_list[i]));
			delete (flagged_enemy_list[i]);
		}
		flagged_enemy_list.clear();
	}
	
	Enemy::EnemyService::~EnemyService()
	{
		destroy();
		spawn_timer = 0.0f;
	}

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(enemy_list[i]));
			delete (enemy_list[i]);
		}
		enemy_list.clear();
	}

	void EnemyService::reset() 
	{
		destroy();
		spawn_timer = 0.0f;
	}

}

