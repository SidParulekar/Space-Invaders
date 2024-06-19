#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Config.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Bullet
{
	using namespace Global;
	using namespace UI::UIElement;

	BulletView::BulletView()
	{
		createBulletImage();
	}

	void BulletView::createBulletImage()
	{
		bullet_image = new ImageView();
	}

	void BulletView::initialize(BulletController* controller)
	{
		bullet_controller = controller;
		initializeBulletImage(); 
	}

	void BulletView::initializeBulletImage()
	{
		bullet_image->initialize(getBulletTexturePath(), bullet_sprite_width, bullet_sprite_height, bullet_controller->getProjectilePosition()); 
	}

	sf::String BulletView::getBulletTexturePath()
	{
		switch (bullet_controller->getBulletType())
		{
		case::Bullet::BulletType::LASER_BULLET:
			return Config::laser_bullet_texture_path;
		
		case::Bullet::BulletType::FROST_BULLET:
			return Config::frost_beam_texture_path;
			
		case::Bullet::BulletType::TORPEDO:
			return Config::torpedoe_texture_path;
			
		}
	}

	void BulletView::update()
	{
		bullet_image->setPosition(bullet_controller->getProjectilePosition()); 
		bullet_image->update(); 
	}

	void BulletView::render()
	{
		bullet_image->render();
	}

	BulletView::~BulletView()
	{
		delete bullet_image;
	}
}