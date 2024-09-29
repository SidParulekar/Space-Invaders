#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\UI\Interface\IUIController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\UI\ImageView.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\UI\TextView.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\UI\AnimatedImageView.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float logo_animation_duration = 6.0f;
			float elapsed_duration = 0.0f;
			const float logo_width = 1876.f;
			const float logo_height = 1060.f;

			UIElement::AnimatedImageView* game_logo_view;

			void initializeGameLogo();

			void fadeInAnimationCallback();
			void fadeOutAnimationCallback();

			//void updateTimer();
			//void showMainMenu();
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
