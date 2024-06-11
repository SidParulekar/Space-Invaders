#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\Controllers\SubZeroController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\Controllers\ZapperController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

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
	}

	EnemyType EnemyService::getRandomEnemyType()
	{
		int randomType = std::rand() % 2;
		return static_cast<Enemy::EnemyType>(randomType);
	}

	EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
	{
		switch (enemy_type)
		{
		case::Enemy::EnemyType::ZAPPER:
			return new Controllers::ZapperController(enemy_type); 

			/*case::Enemy::EnemyType::THUNDER_SNAKE:
				return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);*/

		case::Enemy::EnemyType::SUBZERO:
			return new Controllers::SubZeroController(enemy_type);

			/*case::Enemy::EnemyType::UFO:
				return new UFOController(Enemy::EnemyType::UFO);*/
		}
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
		enemy_list.push_back(enemy_controller);

		return enemy_controller;
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
		delete enemy_controller;
	}

	void Enemy::EnemyService::render()
	{
		for (int i = 0; i < enemy_list.size(); i++) enemy_list[i]->render();
	}

	Enemy::EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++) delete (enemy_list[i]);
	}
}

