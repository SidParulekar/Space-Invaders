#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\SplashScreen\SplashScreenUIController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\MainMenu\MainMenuController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\GameplayUI\GameplayUIController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\Interface\IUIController.h"

namespace UI
{
	using namespace SplashScreen;
	using namespace MainMenu;
	using namespace GameplayUI;
	using namespace Interface;
	
	class UIService
	{
	private:
		MainMenuController* main_menu_controller;
		GameplayUIController* gameplay_ui_controller; 
		SplashScreenUIController* splash_screen_ui_controller;

		void createControllers();
		void initializeControllers();
		void destroy(); 


	public:

		UIService();
		~UIService();

		void initialize();
		void update();
		void render();

		void showScreen();

		MainMenuController* getMainMenuController(); 

		IUIController* getCurrentUIController();

	};
}