#pragma once
#include <SFML/Graphics.hpp>

namespace Element
{
	namespace Bunker
	{
		class BunkerController;

		class BunkerView
		{
		private:
			const sf::String bunker_texture_path = "assets/textures/bunker.png";

			const float bunker_sprite_width = 80.f;
			const float bunker_sprite_height = 80.f;

			sf::Texture bunker_texture;
			sf::Sprite bunker_sprite;


			sf::RenderWindow* game_window;

			BunkerController* bunker_controller;

			void initializeBunkerSprite(); // To create the bunker to be rendered in the game window
			void scaleBunkerSprite(); // To set the scale of the bunker according to the specified width and height

		public:
			BunkerView();
			~BunkerView();

			void initialize(BunkerController* controller);
			void update();
			void render();
		};
	}
}