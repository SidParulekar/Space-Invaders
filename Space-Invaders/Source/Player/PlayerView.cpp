#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerView.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Config.h"

namespace Player
{
	using namespace Global;
	using namespace UI::UIElement;

	PlayerView::PlayerView()
	{
		createPlayerImage();
	}

	void PlayerView::createPlayerImage()
	{
		player_image = new ImageView();
	}


	void PlayerView::initialize(PlayerController* controller)
	{
		player_controller = controller;
		initializePlayerImage();
	}

	void PlayerView::initializePlayerImage()
	{
		player_image->initialize(getPlayerTexturePath(), player_sprite_width, player_sprite_height, player_controller->getPlayerPosition()); 
	}

	sf::String PlayerView::getPlayerTexturePath()
	{
		return Config::player_texture_path;
	}

	void PlayerView::update()
	{
		player_image->setPosition(player_controller->getPlayerPosition());
		player_image->update();
	}

	void PlayerView::render()
	{
		player_image->render(); 
	}

	const sf::Sprite& PlayerView::getPlayerSprite()
	{
		return player_image->getImageSprite();
	}

	PlayerView::~PlayerView()
	{
		delete player_image;
	}
}




