#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\PlayerService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

PlayerService::PlayerService()  
{
	game_window = nullptr;
}

PlayerService::~PlayerService() = default;


void PlayerService::initializePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path)) 
	{
		player_sprite.setTexture(player_texture); 
	}
}

void PlayerService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerSprite();
}

void PlayerService::moveLeft()
{
	position.x -= movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

void PlayerService::moveRight()
{
	position.x += movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

void PlayerService::processPlayerInput()
{
	EventService* event_service = ServiceLocator::getInstance()->getEventService();

	if (event_service->isKeyboardEvent())
	{

		if (event_service->pressedLeftKey())
		{
			moveLeft();
		}

		if (event_service->pressedRightKey())
		{
			moveRight();
		}

	}	
}

void PlayerService::update()
{
	processPlayerInput();
	player_sprite.setPosition(getPlayerPosition());
}

sf::Vector2f PlayerService::getPlayerPosition()
{
	return position;
}

void PlayerService::render()
{
	game_window->draw(player_sprite); 
}




