#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\Controllers\LaserBulletController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\Controllers\TorpedoController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\Controllers\FrostBulletController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Bullet
{
	using namespace Controller;
	using namespace Projectile;

	BulletService::BulletService()
	{
	}

	void BulletService::initialize()
	{
	}

	BulletController* BulletService::spawnBullet(BulletType bullet_type, sf::Vector2f position, MovementDirection direction, Entity::EntityType owner_type)
	{
		BulletController* bullet_controller = createBullet(bullet_type);

		bullet_controller->initialize(position, direction);
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
		for (int i = 0; i < bullet_list.size(); i++) delete (bullet_list[i]);
	}
	
	void BulletService::destroyBullet(BulletController* bullet_controller)
	{
		bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller), bullet_list.end());
		delete(bullet_controller);
	}
}
