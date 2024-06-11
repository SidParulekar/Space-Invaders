#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Gameplay\GameplayView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;
	

	GameplayView::GameplayView()
	{
		game_window = nullptr;
	}

	void GameplayView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		//initializeBackgroundImage();
	}

	/*void GameplayView::initializeBackgroundImage()
	{
		if (background_texture.loadFromFile(background_texture_path)) 
		{
			background_sprite.setTexture(background_texture);
			scaleBackgroundImage();
		}
	}

	void GameplayView::scaleBackgroundImage()
	{
		background_sprite.setScale(
			static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
			static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
		);
	}*/

	void GameplayView::update()
	{
	}

	void GameplayView::render()
	{
		background_sprite = ServiceLocator::getInstance()->getUIService()->getMainMenuController()->getBackgroundSprite();
		game_window->draw(background_sprite);
	}

	GameplayView::~GameplayView()
	{
	}

}
