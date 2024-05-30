#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\PlayerView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\PlayerModel.h"
#include <SFML/Graphics.hpp>

class PlayerController
{

private:
	PlayerModel* player_model;
	PlayerView* player_view;

	sf::Vector2f currentPosition;

	void processPlayerInput();
	void moveLeft();
	void moveRight();

public:

	PlayerController();
	~PlayerController();

	void initialize();
	void update();
	void render();

	sf::Vector2f getPlayerPosition();


};