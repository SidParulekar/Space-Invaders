#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletController.h"

namespace Bullet
{
	namespace Controller
	{
		class FrostBulletController :public BulletController
		{
		private:
			const float frost_bullet_movement_speed = 500.f;

		public:
			FrostBulletController(BulletType type);
			~FrostBulletController();

			void initialize(sf::Vector2f position, MovementDirection direction) override;
		};
	}
}