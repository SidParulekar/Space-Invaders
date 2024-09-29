#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\UI\ImageView.h"
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

			BunkerController* bunker_controller;

			UI::UIElement::ImageView* bunker_image;

			void createBunkerImage();
			void initializeBunkerImage();
			sf::String getBunkerTexturePath();

		public:
			BunkerView();
			~BunkerView();

			void initialize(BunkerController* controller);
			void update();
			void render();

			const sf::Sprite& getBunkerSprite();
		};
	}
}