#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\MainMenu\MainMenuController.h"
namespace UI
{
	using namespace MainMenu;

	class UIService
	{
	private:
		MainMenuController* main_menu_controller;   

		void createControllers();
		void initializeControllers();
		void destroy(); 


	public:

		UIService();
		~UIService();

		void initialize();
		void update();
		void render();

		MainMenuController* getMainMenuController(); 

	};
}