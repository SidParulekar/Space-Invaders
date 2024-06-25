#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerController.h"

namespace Player
{
	PlayerService::PlayerService()
	{
		player_controller = new PlayerController(); 
	}

	void PlayerService::initialize()
	{

		player_controller->initialize();  
	}

	void PlayerService::update()
	{
		player_controller->update();
	}

	void PlayerService::enableShield()
	{
		player_controller->enableShield();
	}

	void PlayerService::enableRapidFire()
	{
		player_controller->enableRapidFire();
	}

	void PlayerService::enableTripleLaser()
	{
		player_controller->enableTripleLaser();
	}

	void PlayerService::increaseEnemiesKilled(int val)
	{
		player_controller->increaseEnemiesKilled(val);
	}

	void PlayerService::reset()
	{
		player_controller->reset();
	}

	void PlayerService::render()
	{
		player_controller->render();
	}

	PlayerService::~PlayerService()
	{
		delete player_controller;
	}
}






