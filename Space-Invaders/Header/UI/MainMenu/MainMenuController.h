#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\Interface\IUIController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\ButtonView.h"
#include <SFML/Graphics.hpp>


namespace UI
{
	namespace MainMenu
	{
		class MainMenuController: public Interface::IUIController
		{
		private:
			const float button_width = 400.f;
			const float button_height = 140.f;

			const float play_button_y_position = 500.f;
			const float instructions_button_y_position = 700.f;
			const float quit_button_y_position = 900.f;

			//const float background_alpha = 85.f;

			UIElement::ImageView* background_image;

			UIElement::ButtonView* play_button;
			UIElement::ButtonView* instructions_button;
			UIElement::ButtonView* quit_button;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeButtons();
			void registerButtonCallback();


			void playButtonCallback(); 
			void instructionsButtonCallback();
			void quitButtonCallback();

			
			void destroy(); 

		public:
			MainMenuController();
			~MainMenuController(); 

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

			sf::Sprite getBackgroundSprite();
		};
	}
}
