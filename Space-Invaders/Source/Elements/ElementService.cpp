#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Elements\ElementService.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Elements\Bunker\BunkerController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Element
{
	using namespace Global;
	
	ElementService::ElementService()
	{
	}
	
	void ElementService::initialize()
	{
		spawnBunkers();
	}

	void ElementService::spawnBunkers()
	{
		for (int i = 0; i < bunker_data_list.size(); i++) //amount of bunkers 
		{
			Bunker::BunkerController* bunker_controller = new Bunker::BunkerController(); //create new controllers   

			bunker_controller->initialize(bunker_data_list[i]); //init them 

			ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(bunker_controller));
			bunker_list.push_back(bunker_controller); //add them to vector of bunker controller pointers   
		}
	}

	void ElementService::update()
	{
		for (int i = 0; i < bunker_list.size(); i++) bunker_list[i]->update();
		destroyFlaggedBunkers();
	}

	void ElementService::render()
	{
		for (int i = 0; i < bunker_list.size(); i++) bunker_list[i]->render(); 
	}

	void ElementService::destroyBunker(Bunker::BunkerController* bunker_controller)
	{
		ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(bunker_controller->getBunkerPosition(),
			Animation::AnimationType::EXPLOSION);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::EXPLOSION);

		flagged_bunker_list.push_back(bunker_controller);
		bunker_list.erase(std::remove(bunker_list.begin(), bunker_list.end(), bunker_controller), bunker_list.end());
	}

	void ElementService::destroyFlaggedBunkers()
	{
		for (int i = 0; i < flagged_bunker_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_bunker_list[i]));
			delete (flagged_bunker_list[i]);
		}
		flagged_bunker_list.clear();
	}

	ElementService::~ElementService()
	{
		destroy();
	}

	void ElementService::destroy()
	{
		for (int i = 0; i < bunker_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(bunker_list[i]));
			delete(bunker_list[i]);
		}
		bunker_list.clear();
	}

	void ElementService::reset()
	{
		destroy();
		spawnBunkers();
	}
}