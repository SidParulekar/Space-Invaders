#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyView;
	class EnemyModel;

	class EnemyController
	{
	private:

		EnemyView* enemy_view;
		EnemyModel* enemy_model;

		float horizontal_movement_speed;
		float vertical_movement_speed;

		virtual void move() = 0;
		void moveLeft();
		void moveRight();
		void moveDown();

		void getRandomInitialPosition();
		void handleOutOfBounds();

	public:
		EnemyController();
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();
		
		sf::Vector2f getEnemyPosition();

		float getHorizontalMovementSpeed();
		void setHorizontalMovementSpeed(float speed);

		float getVerticalMovementSpeed();
		void setVerticalMovementSpeed(float speed);

		EnemyType getEnemyType();
	};
}