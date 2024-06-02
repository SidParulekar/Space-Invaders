#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include <SFML/Graphics.hpp>

class GameService
{
private:
	ServiceLocator* service_locator;
	sf::RenderWindow* game_window;

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
};