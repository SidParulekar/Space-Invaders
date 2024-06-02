#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerController.h" 

namespace Player
{
	using namespace Global;

	PlayerView::PlayerView()
	{
		game_window = nullptr;
	}

	void PlayerView::scalePlayerSprite()
	{
		player_sprite.setScale(
			static_cast<float>(player_sprite_width) / player_sprite.getTexture()->getSize().x,
			static_cast<float>(player_sprite_height) / player_sprite.getTexture()->getSize().y
		);
	}

	void PlayerView::initializePlayerSprite()
	{
		if (player_texture.loadFromFile(player_texture_path))
		{
			player_sprite.setTexture(player_texture);
			scalePlayerSprite();
		}
	}

	void PlayerView::initialize(PlayerController* controller)
	{
		player_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializePlayerSprite();
	}

	void PlayerView::update()
	{
		player_sprite.setPosition(player_controller->getPlayerPosition());
	}

	void PlayerView::render()
	{
		game_window->draw(player_sprite);
	}

	PlayerView::~PlayerView()
	{
	}
}




