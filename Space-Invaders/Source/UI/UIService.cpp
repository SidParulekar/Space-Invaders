#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\UIService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Game\GameService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\TextView.h"

namespace UI
{
	using namespace Game;
	using namespace Interface;
	using namespace UIElement;

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		gameplay_ui_controller = nullptr;
		createControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuController();
		gameplay_ui_controller = new GameplayUIController(); 
	}
	
	void UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
		gameplay_ui_controller->initialize();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller)
		{
			ui_controller->update();
		}
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller)
		{
			ui_controller->render();
		}
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller)
		{
			ui_controller->show(); 
		}
	}

	MainMenuController* UIService::getMainMenuController()
	{
		return main_menu_controller;
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState()) 
		{
		case GameState::MAIN_MENU: 
			return main_menu_controller;

		case GameState::GAMEPLAY:
			return gameplay_ui_controller;

		default:
			return nullptr;
		}
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

