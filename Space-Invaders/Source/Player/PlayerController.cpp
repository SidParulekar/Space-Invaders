#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerView.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerModel.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Powerups\PowerupController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletConfig.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Entities\EntityConfig.h"

#include <algorithm>

namespace Player
{
	using namespace Global;
	using namespace Entity;

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

	void PlayerController::update()
	{
		switch (getPlayerState()) 
		{
		case::Player::PlayerState::ALIVE: 
			processPlayerInput(); 
			break;

		case::Player::PlayerState::FROZEN: 
			updateFreezeDuration(); 
			break;
		}

		updatePowerupDuration(); 
		updateFireDuration(); 
		player_view->update();
	}

	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}


	void PlayerController::processPlayerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedLeftKey() || event_service->pressedAKey())
		{
			moveLeft();
		}

		if (event_service->pressedRightKey() || event_service->pressedDKey())
		{
			moveRight();
		}

		if (event_service->pressedLeftMouseButton())
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::FIRE_BULLET);
			processBulletFire(); 
		}
	}

	void PlayerController::moveLeft()
	{
		currentPosition = getPlayerPosition();
		currentPosition.x -= player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::max(currentPosition.x, player_model->left_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::moveRight()
	{
		currentPosition = getPlayerPosition();
		currentPosition.x += player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::min(currentPosition.x, player_model->right_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::processBulletFire()
	{
		if (player_model->elapsed_fire_duration > 0) return;

		if (player_model->isTripleLaserEnabled())
			fireBullet(true);

		else fireBullet();

		if (player_model->isRapidFireEnabled())
			player_model->elapsed_fire_duration = player_model->rapid_fire_cooldown_duration;

		else player_model->elapsed_fire_duration = player_model->fire_cooldown_duration;
	}

	void PlayerController::fireBullet(bool b_tripple_laser)
	{
		sf::Vector2f bullet_position = player_model->getPlayerPosition() + player_model->bullet_position_offset;
		fireBullet(bullet_position);

		if (b_tripple_laser)
		{
			fireBullet(bullet_position + player_model->second_weapon_position_offset);
			fireBullet(bullet_position + player_model->third_weapon_position_offset);
		}
	}

	void PlayerController::fireBullet(sf::Vector2f position)
	{
		ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET,
			position, Bullet::MovementDirection::UP, player_model->getEntityType());
	}

	void PlayerController::updatePowerupDuration()
	{
		if (player_model->elapsed_shield_duration > 0)
		{
			player_model->elapsed_shield_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (player_model->elapsed_shield_duration <= 0)
				disableShield();
		}

		if (player_model->elapsed_rapid_fire_duration > 0)
		{
			player_model->elapsed_rapid_fire_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (player_model->elapsed_rapid_fire_duration <= 0)
				disableRapidFire();
		}

		if (player_model->elapsed_triple_laser_duration > 0)
		{
			player_model->elapsed_triple_laser_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (player_model->elapsed_triple_laser_duration <= 0)
				disableTripleLaser();
		}
	}

	void PlayerController::updateFireDuration()
	{
		if (player_model->elapsed_fire_duration >= 0)
		{
			player_model->elapsed_fire_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		}
	}

	void PlayerController::updateFreezeDuration()
	{
		if (player_model->elapsed_freeze_duration > 0)
		{
			player_model->elapsed_freeze_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (player_model->elapsed_freeze_duration <= 0)
			{
				player_model->setPlayerState(PlayerState::ALIVE);
			}
		}
	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}

	void PlayerController::reset()
	{
		player_model->reset();
	}

	const sf::Sprite& PlayerController::getColliderSprite()
	{
		return player_view->getPlayerSprite();
	}

	void PlayerController::onCollision(ICollider* other_collider)
	{
		if (processPowerupCollision(other_collider))
			return;

		if (processBulletCollision(other_collider))
			return;

		processEnemyCollision(other_collider); 
	}

	bool PlayerController::processBulletCollision(ICollider* other_collider)
	{
		if (player_model->isShieldEnabled())
			return false;
		
		//If player has collided with a bullet fired by enemy
		BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);

		if (bullet_controller && bullet_controller->getOwnerEntityType() != EntityType::PLAYER)
		{
			if (bullet_controller->getBulletType() == BulletType::FROST_BULLET)
			{
				freezePlayer();
			}
			else decreasePlayerLives();
			return true;
		}

	}

	void PlayerController::freezePlayer()
	{
		player_model->setPlayerState(PlayerState::FROZEN);
		player_model->elapsed_freeze_duration = player_model->freeze_duration;
	}

	bool PlayerController::processEnemyCollision(ICollider* other_collider)
	{
		if (player_model->isShieldEnabled())
			return false;

		//If player has collided with an enemy
		EnemyController* enemy_controller = dynamic_cast<EnemyController*>(other_collider);
		if (enemy_controller)
		{
			decreasePlayerLives();
			return true;
		}
		return false;
	}

	bool PlayerController::processPowerupCollision(ICollider* other_collider)
	{
		//If player has collided with a powerup
		PowerupController* powerup_controller = dynamic_cast<PowerupController*>(other_collider);
		if (powerup_controller)
		{
			return true;
		}
		return false;
	}

	void PlayerController::decreasePlayerLives()
	{
		PlayerModel::player_lives -= 1;

		ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(getPlayerPosition(),
			Animation::AnimationType::EXPLOSION);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::EXPLOSION);

		if (PlayerModel::player_lives <= 0)
		{
			ServiceLocator::getInstance()->getGameplayService()->restart();
		}

		else reset(); 
	}

	void PlayerController::enableShield()
	{
		player_model->elapsed_shield_duration = player_model->shield_powerup_duration;
		player_model->setShieldState(true);
	}

	void PlayerController::disableShield()
	{
		player_model->setShieldState(false);
	}

	void PlayerController::enableRapidFire()
	{
		player_model->elapsed_rapid_fire_duration = player_model->rapid_fire_powerup_duration;
		player_model->setRapidFireState(true);
	}

	void PlayerController::disableRapidFire()
	{
		player_model->setRapidFireState(false);
	}

	void PlayerController::enableTripleLaser()
	{
		player_model->elapsed_triple_laser_duration = player_model->triple_laser_powerup_duration;
		player_model->setTripleFireState(true);
	}

	void PlayerController::disableTripleLaser()
	{
		player_model->setTripleFireState(false);
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


