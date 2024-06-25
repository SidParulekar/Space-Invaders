#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Collisions\ICollider.h"
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyView;
	class EnemyModel;

	enum class EnemyType;
	enum class EnemyState;

	class EnemyController: public Collision::ICollider
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

		void destroy();

	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();
		
		sf::Vector2f getEnemyPosition();

		EnemyType getEnemyType();
		EnemyState getEnemyState(); 

		const sf::Sprite& getColliderSprite() override;
		virtual void onCollision(ICollider* other_collider) override;
	};
}