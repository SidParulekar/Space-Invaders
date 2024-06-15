#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Elements\Bunker\BunkerController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Elements\Bunker\BunkerView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Element
{
	using namespace Global;
	namespace Bunker
	{
		BunkerView::BunkerView()
		{
		}

		void BunkerView::initialize(BunkerController* controller)
		{
			bunker_controller = controller;
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeBunkerSprite();
		}

		void BunkerView::initializeBunkerSprite()
		{
			if (bunker_texture.loadFromFile(bunker_texture_path))
			{
				bunker_sprite.setTexture(bunker_texture);
				scaleBunkerSprite();
			}
		}

		void BunkerView::scaleBunkerSprite()
		{
			bunker_sprite.setScale(
				static_cast<float>(bunker_sprite_width) / bunker_sprite.getTexture()->getSize().x, 
				static_cast<float>(bunker_sprite_height) / bunker_sprite.getTexture()->getSize().y 
			);
		}
		
		void BunkerView::update()
		{
			bunker_sprite.setPosition(bunker_controller->getBunkerPosition()); 
		}

		void BunkerView::render()
		{
			game_window->draw(bunker_sprite); 
		}

		BunkerView::~BunkerView()
		{
		}
	}
}