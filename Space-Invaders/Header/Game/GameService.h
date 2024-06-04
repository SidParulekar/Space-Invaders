#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include <SFML/Graphics.hpp>

namespace Game
{
	using namespace Global; 
	
	enum class GameState
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY
	};

	class GameService
	{
	private:
		ServiceLocator* service_locator; 
		sf::RenderWindow* game_window;

		static GameState current_state;

		void showMainMenu();

		void initialize();
		void initializeVariables();
		void destroy();

	public:
		GameService();
		~GameService();

		void ignite();
		void update();
		void render();
		bool isRunning();

		static void setGameState(GameState new_state);
		static GameState getGameState();
	};

}

