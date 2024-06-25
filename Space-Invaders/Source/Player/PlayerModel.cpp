#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerModel.h"

namespace Player
{
	PlayerModel::PlayerModel()
	{
		entity_type = Entity::EntityType::PLAYER;
	}

	PlayerModel::~PlayerModel()
	{

	}

	void PlayerModel::initialize()
	{
		reset();
	}

	void PlayerModel::reset()
	{
		player_state = PlayerState::ALIVE;
		player_position = initial_player_position;
		player_score = 0;

		player_lives = max_player_lives;
		enemies_killed = 0;

		b_shield = false;
		b_rapid_fire = false;
		b_triple_laser = false;
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

	Entity::EntityType PlayerModel::getEntityType()
	{
		return entity_type;
	}

	void PlayerModel::setShieldState(bool value)
	{
		b_shield = value;
	}

	bool PlayerModel::isShieldEnabled()
	{
		return b_shield;
	}

	void PlayerModel::setRapidFireState(bool value)
	{
		b_rapid_fire = value;
	}

	bool PlayerModel::isRapidFireEnabled()
	{
		return b_rapid_fire;
	}

	void PlayerModel::setTripleFireState(bool value)
	{
		b_triple_laser = value;
	}

	bool PlayerModel::isTripleLaserEnabled()
	{
		return b_triple_laser; 
	}
	
}




