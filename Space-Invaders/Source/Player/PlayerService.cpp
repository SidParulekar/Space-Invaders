#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerController.h"

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

void PlayerService::render()
{
	player_controller->render(); 
}

PlayerService::~PlayerService()
{
	delete player_controller;
}




