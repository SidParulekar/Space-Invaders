#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerModel.h"

PlayerModel::PlayerModel()
{

}

PlayerModel::~PlayerModel()
{

}

void PlayerModel::reset()
{
	player_state = PlayerState::ALIVE;
	player_position = initial_player_position;
	player_score = 0;
}

void PlayerModel::initialize()
{
	reset();
}

void PlayerModel::setPlayerState(PlayerState state)
{
	player_state = state;
}

PlayerState PlayerModel::getPlayerState()
{
	return player_state;
}

void PlayerModel::setPlayerScore(int score)
{
	player_score = score;
}

int PlayerModel::getPlayerScore()
{
	return player_score;
}

void PlayerModel::setPlayerPosition(sf::Vector2f position)
{
	player_position = position;
}

sf::Vector2f PlayerModel::getPlayerPosition()
{
	return player_position;
}


