#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Elements\ElementService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Elements\Bunker\BunkerController.h"

namespace Element
{
	
	ElementService::ElementService()
	{
	}
	
	void ElementService::initialize()
	{
		for (int i = 0; i < bunker_data_list.size(); i++) //amount of bunkers 
		{
			Bunker::BunkerController* bunker_controller = new Bunker::BunkerController(); //create new controllers   

			bunker_controller->initialize(bunker_data_list[i]); //init them   
			bunker_list.push_back(bunker_controller); //add them to vector of bunker controller pointers   
		}
	}

	void ElementService::update()
	{
		for (int i = 0; i < bunker_list.size(); i++) bunker_list[i]->update(); 
	}

	void ElementService::render()
	{
		for (int i = 0; i < bunker_list.size(); i++) bunker_list[i]->render(); 
	}

	ElementService::~ElementService()
	{
		destroy();
	}

	void ElementService::destroy()
	{
		for (int i = 0; i < bunker_list.size(); i++) delete bunker_list[i];
	}
}