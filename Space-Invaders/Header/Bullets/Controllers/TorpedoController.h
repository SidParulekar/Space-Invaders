#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletController.h"

namespace Bullet
{
	namespace Controller
	{
		class TorpedoController :public BulletController
		{
		private:
			const float torpedo_movement_speed = 200.f;

		public:
			TorpedoController(BulletType type, Entity::EntityType owner_type);
			~TorpedoController();

			void initialize(sf::Vector2f position, MovementDirection direction) override;
		};
	}	
}