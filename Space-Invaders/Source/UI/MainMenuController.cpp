#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\MainMenu\MainMenuController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Graphic\GraphicService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Event\EventService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Game\GameService.h"

namespace UI
{
	namespace MainMenu
	{
		using namespace Global; 
		using namespace Game;
		using namespace Graphic;
		using namespace Event;

		MainMenuController::MainMenuController()
		{
			game_window = nullptr;
		}

		void MainMenuController::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();  
		}

		void MainMenuController::update()
		{
		}

		void MainMenuController::render()
		{
		}
	}
}


