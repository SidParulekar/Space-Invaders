#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Elements\Bunker\BunkerController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Elements\Bunker\BunkerView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Config.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Element
{
	using namespace Global;
	using namespace UI::UIElement;

	namespace Bunker
	{
		BunkerView::BunkerView()
		{
			createBunkerImage();
		}

		void BunkerView::createBunkerImage()
		{
			bunker_image = new ImageView();
		}

		void BunkerView::initialize(BunkerController* controller)
		{
			bunker_controller = controller;
			initializeBunkerImage();
		}

		void BunkerView::initializeBunkerImage()
		{
			bunker_image->initialize(getBunkerTexturePath(), bunker_sprite_width, bunker_sprite_height, bunker_controller->getBunkerPosition());
		}

		sf::String BunkerView::getBunkerTexturePath()
		{
			return Config::bunker_texture_path;
		}		
		
		void BunkerView::update()
		{
			bunker_image->setPosition(bunker_controller->getBunkerPosition());
			bunker_image->update(); 
		}

		void BunkerView::render()
		{
			bunker_image->render(); 
		}

		BunkerView::~BunkerView()
		{
			delete bunker_image; 
		}
	}
}