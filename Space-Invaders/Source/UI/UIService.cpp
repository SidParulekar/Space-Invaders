#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\UIService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Game\GameService.h"

namespace UI
{
	using namespace MainMenu;

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		createControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuController();
	}
	
	void UIService::initialize()
	{
		initializeControllers();
	}

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
	}

	void UIService::update()
	{
	}

	void UIService::render()
	{
		main_menu_controller->render();
	}

	UIService::~UIService() 
	{
		destroy();
	}

	void UIService::destroy()
	{
		delete main_menu_controller;
	}

	
}

