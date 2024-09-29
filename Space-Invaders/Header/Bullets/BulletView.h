#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\UI\ImageView.h"
#include <SFML/Graphics.hpp>

namespace Bullet
{
	class BulletController;
	enum class BulletType;

	class BulletView
	{
	private:
		const float bullet_sprite_width = 18.f;
		const float bullet_sprite_height = 18.f;

		BulletController* bullet_controller;

		UI::UIElement::ImageView* bullet_image;

		void createBulletImage();
		void initializeBulletImage();
		sf::String getBulletTexturePath();

	public:
		BulletView();
		~BulletView();

		void initialize(BulletController* controller);
		void update();
		void render();

		const sf::Sprite& getBulletSprite();
	};
}