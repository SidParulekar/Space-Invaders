#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletController.h"

namespace Bullet
{
	namespace Controller
	{
		class LaserBulletController : public BulletController
		{
		public:
			LaserBulletController(BulletType type, Entity::EntityType owner_type);
			~LaserBulletController();

			void initialize(sf::Vector2f position, MovementDirection direction) override;
		};
	}	
}