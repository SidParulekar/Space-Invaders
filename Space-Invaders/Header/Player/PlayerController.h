#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Collisions\ICollider.h"
#include <SFML/Graphics.hpp>

namespace Player
{
	enum class PlayerState;
	class PlayerView;
	class PlayerModel;

	class PlayerController: public Collision::ICollider
	{

	private:
		PlayerModel* player_model;
		PlayerView* player_view;

		sf::Vector2f currentPosition;

		float elapsed_shield_duration;
		float elapsed_rapid_fire_duration;
		float elapsed_triple_laser_duration;

		float elapsed_fire_duration;
		float elapsed_freeze_duration;


		void processPlayerInput();
		void moveLeft();
		void moveRight();

		bool processBulletCollision(ICollider* other_collider);
		bool processPowerupCollision(ICollider* other_collider);
		bool processEnemyCollision(ICollider* other_collider);
		void updateFreezeDuration();
		void freezePlayer();

		void updateFireDuration();
		void processBulletFire();
		void fireBullet(bool b_triple_laser = false);
		void fireBullet(sf::Vector2f position);

		void updatePowerupDuration();

		void disableShield();
		void disableRapidFire();
		void disableTripleLaser();

		//void fireBullet();

	public:

		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		sf::Vector2f getPlayerPosition();
		PlayerState getPlayerState();

		void reset();

		void enableShield();
		void enableRapidFire();
		void enableTripleLaser();

		const sf::Sprite getColliderSprite() override;
		void onCollision(ICollider* other_collider) override;


	};
}
