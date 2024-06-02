#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerModel.h"
#include <algorithm>

namespace Player
{
	using namespace Global;

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView();
	}

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize(this);
	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}

	void PlayerController::moveLeft()
	{
		currentPosition = player_model->getPlayerPosition();
		currentPosition.x -= player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::max(currentPosition.x, player_model->left_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::moveRight()
	{
		currentPosition = player_model->getPlayerPosition();
		currentPosition.x += player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::min(currentPosition.x, player_model->right_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::processPlayerInput()
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
		{
			moveLeft();
		}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
		{
			moveRight();
		}
	}

	void PlayerController::update()
	{
		processPlayerInput();
		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	PlayerController::~PlayerController()
	{
		delete player_model;
		delete player_view;
		player_model = nullptr;
		player_view = nullptr;
	}
}


