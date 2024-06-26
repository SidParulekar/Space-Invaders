#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\ImageView.h"
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyView
	{
	private:

		const float enemy_sprite_width = 60.f;
		const float enemy_sprite_height = 60.f;

		EnemyController* enemy_controller;

		UI::UIElement::ImageView* enemy_image;

		void createEnemyImage();
		void initializeEnemyImage();
		sf::String getEnemyTexturePath();

	public:
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* controller);
		void update();
		void render();

		const sf::Sprite& getEnemySprite();
	};
}