#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletModel.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Bullet
{
	using namespace Global;

	BulletController::BulletController(BulletType type, Entity::EntityType owner_entity)
	{
		bullet_view = new BulletView();
		bullet_model = new BulletModel(type, owner_entity);
	}

	void BulletController::initialize(sf::Vector2f position, MovementDirection direction)
	{
		bullet_view->initialize(this);
		bullet_model->initialize(position, direction);
	}

	void BulletController::update()
	{
		updateProjectilePosition();
		bullet_view->update();
		handleOutOfBounds();
	}

	void BulletController::updateProjectilePosition()
	{
		switch (bullet_model->getMovementDirection())
		{
		case::Bullet::MovementDirection::UP:
			moveUp();
			break;

		case::Bullet::MovementDirection::DOWN:
			moveDown();
			break;
		}
	}

	void BulletController::moveUp()
	{
		sf::Vector2f currentPosition = bullet_model->getBulletPosition();
		currentPosition.y -= bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setBulletPosition(currentPosition);
	}

	void BulletController::moveDown()
	{
		sf::Vector2f currentPosition = bullet_model->getBulletPosition();

		currentPosition.y += bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setBulletPosition(currentPosition);
	}

	void BulletController::handleOutOfBounds()
	{
		sf::Vector2f bulletPosition = getProjectilePosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (bulletPosition.x < 0 || bulletPosition.x > windowSize.x ||
			bulletPosition.y < 0 || bulletPosition.y > windowSize.y)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	void BulletController::render()
	{
		bullet_view->render();
	}

	sf::Vector2f BulletController::getProjectilePosition()
	{
		return bullet_model->getBulletPosition();
	}

	BulletType BulletController::getBulletType()
	{
		return bullet_model->getBulletType();
	}

	Entity::EntityType BulletController::getOwnerEntityType()
	{
		return Entity::EntityType();
	}

	BulletController::~BulletController()
	{
		delete bullet_view;
		delete bullet_model;
	}

}