#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletConfig.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletConfig.h"
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
			return BulletConfig::getBulletTexturePath(bullet_controller->getBulletType());	
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

	const sf::Sprite& BulletView::getBulletSprite()
	{
		return bullet_image->getImageSprite();
	}

	BulletView::~BulletView()
	{
		delete bullet_image;
	}
}