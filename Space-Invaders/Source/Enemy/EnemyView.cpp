#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyView.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyConfig.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Config.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"

namespace Enemy
{
	using namespace Global;
	using namespace UI::UIElement;

	EnemyView::EnemyView()
	{
		createEnemyImage();
	}

	void EnemyView::createEnemyImage()
	{
		enemy_image = new ImageView();
	}

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		initializeEnemyImage();
	}

	void EnemyView::initializeEnemyImage()
	{
		enemy_image->initialize(getEnemyTexturePath(), enemy_sprite_width, enemy_sprite_height, enemy_controller->getEnemyPosition()); 
	}

	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemy_controller->getEnemyType())
		{
		case::Enemy::EnemyType::SUBZERO:
			return Config::subzero_texture_path;
			
		case::Enemy::EnemyType::ZAPPER:
			return Config::zapper_texture_path;
			
		case::Enemy::EnemyType::UFO:
			return Config::ufo_texture_path;

		case::Enemy::EnemyType::THUNDER_SNAKE:
			return Config::thunder_snake_texture_path;
			
		}
	}
	
	void EnemyView::update()
	{
		enemy_image->setPosition(enemy_controller->getEnemyPosition());
		enemy_image->update();
	}

	void EnemyView::render()
	{
		enemy_image->render();
	}


	const sf::Sprite& EnemyView::getEnemySprite()
	{
		return enemy_image->getImageSprite();
	}

	EnemyView::~EnemyView()
	{
		delete enemy_image;
	}
}