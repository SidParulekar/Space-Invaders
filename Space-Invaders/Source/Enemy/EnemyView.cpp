#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Config.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"

namespace Enemy
{
	using namespace Global;

	EnemyView::EnemyView()
	{
		game_window = nullptr;
	}
	
	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeEnemySprite(enemy_controller->getEnemyType());
	}

	void EnemyView::initializeEnemySprite(EnemyType type)
	{
		switch (type)
		{
		case::Enemy::EnemyType::SUBZERO:
			if (enemy_texture.loadFromFile(Config::subzero_texture_path)) 
			{
				enemy_sprite.setTexture(enemy_texture);
				scaleEnemySprite();
			}
			break;
		case::Enemy::EnemyType::ZAPPER:
			if (enemy_texture.loadFromFile(Config::zapper_texture_path)) 
			{
				enemy_sprite.setTexture(enemy_texture);
				scaleEnemySprite();
			}
			break;
		case::Enemy::EnemyType::UFO:
			if (enemy_texture.loadFromFile(Config::ufo_texture_path)) 
			{
				enemy_sprite.setTexture(enemy_texture);
				scaleEnemySprite();
			}
			break;

		}
	}
	void EnemyView::scaleEnemySprite()
	{
		enemy_sprite.setScale(
			static_cast<float>(enemy_sprite_width) / enemy_sprite.getTexture()->getSize().x,
			static_cast<float>(enemy_sprite_height) / enemy_sprite.getTexture()->getSize().y
		);
	}
	
	void EnemyView::update()
	{
		enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
	}

	void EnemyView::render()
	{
		game_window->draw(enemy_sprite);
	}

	EnemyView::~EnemyView()
	{
	}
}