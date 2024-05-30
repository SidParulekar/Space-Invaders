#pragma once
#include <SFML/Graphics.hpp>

enum PlayerState
{
	ALIVE,
	DEAD
};

class PlayerModel
{
private:
	const sf::Vector2f initial_player_position = sf::Vector2f(500.0f, 500.0f);
	sf::Vector2f player_position;
	//bool player_alive;
	PlayerState player_state;
	int player_score;

public:
	const float player_movement_speed = 200.0f;

	const sf::Vector2f left_most_position = sf::Vector2f(50.f, 0.f);
	const sf::Vector2f right_most_position = sf::Vector2f(700.f, 0.f);

	PlayerModel();
	~PlayerModel();

	void initialize();

	void reset();

	/*bool getPlayerAlive();
	void setPlayerAlive(bool alive);*/

	PlayerState getPlayerState();
	void setPlayerState(PlayerState state);

	int getPlayerScore();
	void setPlayerScore(int score);

	sf::Vector2f getPlayerPosition();
	void setPlayerPosition(sf::Vector2f position);

};