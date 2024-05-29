#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\GameService.h"

GameService::GameService() //Constructor
{
	service_locator = nullptr;
	game_window = nullptr;
}

GameService::~GameService() // Destroys instances and frees up memory
{
	destroy();
}

void GameService::ignite() // Starts the game
{
	service_locator = ServiceLocator::getInstance();
	initialize();
}

void GameService::initialize() //Sets up the game
{
	service_locator->initialize();
	initializeVariables();
}

void GameService::initializeVariables() //Initialize game window pointer with new game window instance 
{
	game_window = service_locator->getGraphicService()->getGameWindow(); 
}

void GameService::update() //Updates game state
{
	service_locator->getEventService()->processEvents();

	service_locator->update(); 
}

void GameService::render() // Renders each frame in the game window
{

	//Sets Game window with background color as specified in GraphicService
	game_window->clear(service_locator->getGraphicService()->getWindowColor());

	service_locator->render();
	
	game_window->display(); 
}

void GameService::destroy() //Performs clean up tasks
{
	delete game_window;
}

bool GameService::isRunning() // Checks whether the game is still running 
{
	return service_locator->getGraphicService()->isGameWindowOpen();
}
