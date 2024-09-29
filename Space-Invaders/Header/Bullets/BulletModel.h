#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Entities\EntityConfig.h"
#include <SFML/System/Vector2.hpp>

namespace Bullet
{
	enum class MovementDirection;
	enum class BulletType;

	class BulletModel
	{
	private:
		float bullet_speed = 300.0f;
		sf::Vector2f bullet_position;

		MovementDirection bullet_direction;
		BulletType bullet_type;
		Entity::EntityType owner_entity;

	public:

		BulletModel(BulletType type, Entity::EntityType owner_type);
		~BulletModel();

		void initialize(sf::Vector2f position, MovementDirection direction);
		
		sf::Vector2f getBulletPosition();
		void setBulletPosition(sf::Vector2f position);

		BulletType getBulletType();
		void setBulletType(BulletType type);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		float getMovementSpeed();
		void setMovementSpeed(float speed);

		Entity::EntityType getOwnerEntityType();


	};
}