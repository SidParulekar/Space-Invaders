#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletModel.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletConfig.h"


namespace Bullet
{
	BulletModel::BulletModel(BulletType type, Entity::EntityType owner_type)
	{
		bullet_type = type;
		owner_entity = owner_type;
	}

	void BulletModel::initialize(sf::Vector2f position, MovementDirection direction)
	{
		bullet_direction = direction;
		bullet_position = position;
	}

	void BulletModel::setBulletPosition(sf::Vector2f position)
	{
		bullet_position = position;
	}

	sf::Vector2f BulletModel::getBulletPosition()
	{
		return bullet_position;
	}

	void BulletModel::setBulletType(BulletType type)
	{
		bullet_type = type;
	}

	BulletType BulletModel::getBulletType()
	{
		return bullet_type;
	}

	void BulletModel::setMovementDirection(MovementDirection direction)
	{
		bullet_direction = direction;
	}

	MovementDirection BulletModel::getMovementDirection()
	{
		return bullet_direction;
	}
	
	void BulletModel::setMovementSpeed(float speed)
	{
		bullet_speed = speed;
	}

	Entity::EntityType BulletModel::getOwnerEntityType()
	{
		return owner_entity;
	}

	float BulletModel::getMovementSpeed()
	{
		return bullet_speed;
	}

	BulletModel::~BulletModel()
	{
	}
	
}

