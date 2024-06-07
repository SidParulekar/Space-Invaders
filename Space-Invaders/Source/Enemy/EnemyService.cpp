#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Time\TimeService.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;

	Enemy::EnemyService::EnemyService()
	{
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

	void EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = new EnemyController();
		enemy_controller->initialize();

		enemy_list.push_back(enemy_controller);
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

