#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Gameplay\GameplayController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Gameplay\GameplayView.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Gameplay
{
	GameplayController::GameplayController()
	{
		gameplay_view = new GameplayView(); 
	}
	
	void GameplayController::initialize()
	{	
		gameplay_view->initialize(); 
	}

	void GameplayController::update()
	{
		gameplay_view->update();
	}

	void GameplayController::render()
	{
		gameplay_view->render(); 
	}

	GameplayController::~GameplayController()
	{
		delete gameplay_view;
		gameplay_view = nullptr;
	}
}