#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\Interface\IUIController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\ImageView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\TextView.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float splash_screen_duration = 10.0f;
			float elapsed_duration = 0.0f;
			const float logo_width = 1876.f;
			const float logo_height = 1060.f;

			UIElement::ImageView* game_logo_view;

			void initializeGameLogo();
			void updateTimer();
			void showMainMenu();
			sf::Vector2f getLogoPosition();

		public:


			SplashScreenUIController();
			~SplashScreenUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}
