#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Gameplay\GameplayService.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Gameplay\GameplayController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;

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

	void GameplayService::restart()
	{
		ServiceLocator::getInstance()->getPlayerService()->reset();
		ServiceLocator::getInstance()->getEnemyService()->reset();
		ServiceLocator::getInstance()->getBulletService()->reset();
		ServiceLocator::getInstance()->getElementService()->reset();
	}

	GameplayService::~GameplayService()
	{
		delete gameplay_controller;
	}
}