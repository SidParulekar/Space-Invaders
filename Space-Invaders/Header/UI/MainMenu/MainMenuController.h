#pragma once

#include <SFML/Graphics.hpp>
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\Interface\IUIController.h"

namespace UI
{
	namespace MainMenu
	{
		class MainMenuController: public Interface::IUIController
		{
		private:
			sf::RenderWindow* game_window;

			const float button_width = 300.0f;
			const float button_height = 300.0f;

			const sf::String background_texture_path = "assets/textures/space_invaders_bg.png";
			const sf::String play_button_texture_path = "assets/textures/play_button.png";
			const sf::String instruction_button_texture_path = "assets/textures/instructions_button.png";
			const sf::String quit_button_texture_path = "assets/textures/quit_button.png";

			sf::Texture background_texture; 
			sf::Sprite background_sprite; 

			sf::Texture play_button_texture;
			sf::Sprite play_button_sprite;

			sf::Texture instructions_button_texture;
			sf::Sprite instructions_button_sprite;

			sf::Texture quit_button_texture;
			sf::Sprite quit_button_sprite;

			void initializeBackgroundImage();
			void scaleBackgroundImage();

			// To create the buttons to be rendered in the game window
			void initializeButtons();
			bool loadButtonTexturesFromFile();
			void setButtonSprites();

			// To set the scale of the buttons according to the specified width and height and set their position
			void scaleAllButttons(); 
			void scaleButton(sf::Sprite* button_to_scale); 
			void positionButtons();

			void processButtonInteractions();
			bool clickedButton(sf::Sprite*, sf::Vector2f);

		public:
			MainMenuController();

			void initialize() override;
			void update() override;
			void render() override;

			void show() override;

			sf::Sprite getBackgroundSprite();
		};
	}
}
