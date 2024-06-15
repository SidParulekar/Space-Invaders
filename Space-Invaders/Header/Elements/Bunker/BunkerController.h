#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Elements\Bunker\BunkerModel.h"
#include <SFML/Graphics.hpp>

namespace Element
{
	namespace Bunker
	{
		class BunkerView;

		class BunkerController
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

		};
	}
}