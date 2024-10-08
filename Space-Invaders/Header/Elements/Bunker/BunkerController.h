#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Elements\Bunker\BunkerModel.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Collisions\ICollider.h"
#include <SFML/Graphics.hpp>

namespace Element
{
	namespace Bunker
	{
		class BunkerView;

		class BunkerController: public Collision::ICollider
		{
		private:
			BunkerView* bunker_view;
			BunkerData bunker_data;

		public:
			BunkerController();
			~BunkerController();

			void initialize(BunkerData data);
			void update();
			void render();

			sf::Vector2f getBunkerPosition();

			const sf::Sprite& getColliderSprite() override;
			void onCollision(ICollider* other_collider) override;

		};
	}
}