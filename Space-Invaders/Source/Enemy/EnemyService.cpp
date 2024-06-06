#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	Enemy::EnemyService::EnemyService()
	{
		enemy_controller = nullptr;
	}

	void Enemy::EnemyService::initialize()
	{
		spawnEnemy();
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		enemy_controller = new EnemyController();
		enemy_controller->initialize();
		return enemy_controller;
	}

	void Enemy::EnemyService::update()
	{
		enemy_controller->update(); 
	}

	void Enemy::EnemyService::render()
	{
		enemy_controller->render();
	}

	Enemy::EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::destroy()
	{
		delete enemy_controller;
	}
}

