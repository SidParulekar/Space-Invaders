#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyModel.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyConfig.h" 

namespace Enemy
{
	EnemyModel::EnemyModel(EnemyType type)
	{
		enemy_type = type;
	}

	EnemyModel::~EnemyModel()
	{
	}

	void EnemyModel::initialize()
	{
		enemy_state = EnemyState::PATROLLING; 
		movement_direction = MovementDirection::RIGHT; 
		enemy_position = reference_position; 
	}

	void EnemyModel::setEnemyPosition(sf::Vector2f position)
	{
		enemy_position = position;
	}
	
	sf::Vector2f EnemyModel::getEnemyPosition()
	{
		return enemy_position;
	}
	
	void EnemyModel::setReferencePosition(sf::Vector2f position)
	{
		reference_position = position;
	}

	sf::Vector2f EnemyModel::getReferencePosition()
	{
		return reference_position;
	}

	void EnemyModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}

	MovementDirection EnemyModel::getMovementDirection()
	{
		return movement_direction;
	}

	void EnemyModel::setEnemyType(EnemyType type)
	{
		enemy_type = type;
	}

	EnemyType EnemyModel::getEnemyType()
	{
		return enemy_type;
	}

	void EnemyModel::setEnemyState(EnemyState state)
	{
		enemy_state = state;
	}

	EnemyState EnemyModel::getEnemyState()
	{
		return enemy_state;
	}

}