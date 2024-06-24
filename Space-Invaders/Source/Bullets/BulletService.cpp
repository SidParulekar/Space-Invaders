#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\Controllers\LaserBulletController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\Controllers\TorpedoController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\Controllers\FrostBulletController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Collisions\ICollider.h"

namespace Bullet
{
	using namespace Global;
	using namespace Controller;
	using namespace Projectile;
	using namespace Collision;

	BulletService::BulletService()
	{
	}

	void BulletService::initialize()
	{
		bullet_list.clear();
		flagged_bullet_list.clear();
	}

	BulletController* BulletService::spawnBullet(BulletType bullet_type, sf::Vector2f position, MovementDirection direction, Entity::EntityType owner_type)
	{
		BulletController* bullet_controller = createBullet(bullet_type, owner_type);
		bullet_controller->initialize(position, direction);

		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(bullet_controller)); 
		bullet_list.push_back(bullet_controller);
		return bullet_controller;
	}

	BulletController* BulletService::createBullet(BulletType bullet_type, Entity::EntityType owner_type)
	{
		switch (bullet_type)
		{
		case::Bullet::BulletType::LASER_BULLET:
			return new LaserBulletController(Bullet::BulletType::LASER_BULLET, owner_type);

		case::Bullet::BulletType::FROST_BULLET:
			return new FrostBulletController(Bullet::BulletType::FROST_BULLET, owner_type);

		case::Bullet::BulletType::TORPEDO:
			return new TorpedoController(Bullet::BulletType::TORPEDO, owner_type);
		}
	}
	
	void BulletService::update()
	{
		for (int i = 0; i < bullet_list.size(); i++) bullet_list[i]->update();

		destroyFlaggedBullets();
	}

	bool BulletService::isValidBullet(int index, std::vector<Projectile::IProjectile*>& bullet_list)
	{
		return index >= 0 && index < bullet_list.size() && bullet_list[index] != nullptr;
	}

	void BulletService::destroyFlaggedBullets()
	{
		for (int i = 0; i < flagged_bullet_list.size(); i++)
		{
			if (!isValidBullet(i, flagged_bullet_list)) continue;

			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_bullet_list[i]));
			delete (flagged_bullet_list[i]);
		}
		flagged_bullet_list.clear();
	}

	void BulletService::render()
	{
		for (int i = 0; i < bullet_list.size(); i++) bullet_list[i]->render();
	}

	BulletService::~BulletService()
	{
		destroy();
	}

	void BulletService::destroy()
	{
		for (int i = 0; i < bullet_list.size(); i++)
		{
			if (!isValidBullet(i, bullet_list)) continue;

			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(bullet_list[i]));
			delete (bullet_list[i]);
		}
		bullet_list.clear();
	}
	
	void BulletService::destroyBullet(BulletController* bullet_controller)
	{
		if (std::find(flagged_bullet_list.begin(), flagged_bullet_list.end(), bullet_controller) == flagged_bullet_list.end()) 
		{
			flagged_bullet_list.push_back(bullet_controller); 
			bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller), bullet_list.end()); 
		}
	}
}
