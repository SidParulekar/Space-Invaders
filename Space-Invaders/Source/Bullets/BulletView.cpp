#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Config.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Bullet
{
	using namespace Global;

	BulletView::BulletView()
	{
	}

	void BulletView::initialize(BulletController* controller)
	{
		bullet_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeBulletSprite(bullet_controller->getBulletType());
	}

	void BulletView::initializeBulletSprite(BulletType type)
	{
		switch (type)
		{
		case::Bullet::BulletType::LASER_BULLET:
			if (bullet_texture.loadFromFile(Config::laser_bullet_texture_path)) 
			{
				bullet_sprite.setTexture(bullet_texture);
				scaleBulletSprite();
			}
			break;
		case::Bullet::BulletType::FROST_BULLET: 
			if (bullet_texture.loadFromFile(Config::frost_beam_texture_path)) 
			{
				bullet_sprite.setTexture(bullet_texture); 
				scaleBulletSprite();
			}
			break;
		case::Bullet::BulletType::TORPEDO: 
			if (bullet_texture.loadFromFile(Config::torpedoe_texture_path)) 
			{
				bullet_sprite.setTexture(bullet_texture); 
				scaleBulletSprite(); 
			}
			break;
		}
	}

	void BulletView::scaleBulletSprite()
	{
		bullet_sprite.setScale(
			static_cast<float>(bullet_sprite_width) / bullet_sprite.getTexture()->getSize().x,
			static_cast<float>(bullet_sprite_height) / bullet_sprite.getTexture()->getSize().y
		);
	}

	void BulletView::update()
	{
		bullet_sprite.setPosition(bullet_controller->getProjectilePosition()); 
	}

	void BulletView::render()
	{
		game_window->draw(bullet_sprite); 
	}

	BulletView::~BulletView()
	{
	}
}