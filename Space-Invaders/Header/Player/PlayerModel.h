#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};

	class PlayerModel
	{
	private:
		const sf::Vector2f initial_player_position = sf::Vector2f(950.0f, 950.0f);
		sf::Vector2f player_position;
		PlayerState player_state;
		int player_score;

	public:
		const float player_movement_speed = 350.0f;

		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f); // Specifies the left most boundary upto which player ship can move 
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f); // Specifies the right most boundary upto which player ship can move
		const sf::Vector2f bullet_position_offset = sf::Vector2f(20.f, 50.f);

		PlayerModel();
		~PlayerModel();

		void initialize();

		void reset(); // Resets all the player data stats to initial values

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);

		int getPlayerScore();
		void setPlayerScore(int score);

		sf::Vector2f getPlayerPosition();
		void setPlayerPosition(sf::Vector2f position);

	};
}
