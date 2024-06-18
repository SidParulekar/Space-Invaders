#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyView;
	class EnemyModel;

	enum class EnemyType;
	enum class EnemyState;

	class EnemyController
	{
	protected:

		EnemyView* enemy_view;
		EnemyModel* enemy_model;

		float rate_of_fire = 3.f;
		float elapsed_fire_duration = 0.f;

		virtual void move() = 0;
		
		sf::Vector2f getRandomInitialPosition();
		void handleOutOfBounds();

		void updateFireTimer();
		void processBulletFire();
		virtual void fireBullet() = 0;

	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();
		
		sf::Vector2f getEnemyPosition();

		EnemyType getEnemyType();
		EnemyState getEnemyState(); 
	};
}