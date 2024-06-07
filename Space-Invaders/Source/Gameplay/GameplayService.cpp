#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Gameplay\GameplayService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Gameplay\GameplayController.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}
	
	void GameplayService::initialize()
	{
		gameplay_controller->initialize(); 
	}

	void GameplayService::update()
	{
		gameplay_controller->update(); 
	}

	void GameplayService::render()
	{
		gameplay_controller->render(); 
	}

	GameplayService::~GameplayService()
	{
		delete gameplay_controller;
	}
}