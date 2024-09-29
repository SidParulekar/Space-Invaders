#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Elements\Bunker\BunkerController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Elements\Bunker\BunkerView.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Bullets\BulletController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyConfig.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"


namespace Element
{
	using namespace Global;

	namespace Bunker
	{
		BunkerController::BunkerController()
		{
			bunker_view = new BunkerView();
		}
		
		void BunkerController::initialize(BunkerData data)
		{
			bunker_data = data;
			bunker_view->initialize(this);
		}

		void BunkerController::update()
		{
			bunker_view->update(); 
		}

		void BunkerController::render()
		{
			bunker_view->render();
		}

		sf::Vector2f BunkerController::getBunkerPosition()
		{
			return bunker_data.bunker_position;
		}

		const sf::Sprite& BunkerController::getColliderSprite()
		{
			return bunker_view->getBunkerSprite();
		}

		void BunkerController::onCollision(ICollider* other_collider)
		{
			//If Bunker has collided with Torpedo
			BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);
			if (bullet_controller && bullet_controller->getBulletType() == BulletType::TORPEDO)
			{
				ServiceLocator::getInstance()->getElementService()->destroyBunker(this);
			}

			//If Bunker has collided with SUBZERO enemy
			EnemyController* enemy_controller = dynamic_cast<EnemyController*>(other_collider);
			if (enemy_controller && enemy_controller->getEnemyType() == EnemyType::SUBZERO)  
			{
				ServiceLocator::getInstance()->getElementService()->destroyBunker(this);
			}
		}

		BunkerController::~BunkerController()
		{
			delete bunker_view;
		}
	}
}