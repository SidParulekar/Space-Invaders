#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	graphic_service = nullptr;
	event_service = nullptr;
	player_service = nullptr;
	time_service = nullptr;
	createServices();

}

//Destructor to clean up resources on object deletion
ServiceLocator::~ServiceLocator() 
{
	clearAllServices(); 
}

// Creates instances of Services
void ServiceLocator::createServices()
{
	graphic_service = new GraphicService();
	event_service = new EventService();
	player_service = new PlayerService();
	time_service = new TimeService();
}

ServiceLocator* ServiceLocator::getInstance()
{
	static ServiceLocator instance;
	return &instance;
}

// Initializes service locator
void ServiceLocator::initialize()
{
	graphic_service->initialize();
	event_service->initialize();
	player_service->initialize();
	time_service->initialize(); 
}

// Updates services
void ServiceLocator::update()
{
	graphic_service->update();
	event_service->update();
	player_service->update();
	time_service->update(); 
}

// Renders the services
void ServiceLocator::render()
{
	graphic_service->render();
	player_service->render(); 
}

GraphicService* ServiceLocator::getGraphicService()
{
	return graphic_service;
}

EventService* ServiceLocator::getEventService()
{
	return event_service;
}

PlayerService* ServiceLocator::getPlayerService()
{
	return player_service;
}

TimeService* ServiceLocator::getTimeService()
{
	return time_service;
}

//deletes service instances and deallocates memory
void ServiceLocator::clearAllServices()
{
	delete graphic_service;
	delete event_service;
	delete player_service;
	delete time_service;
	graphic_service = nullptr;
	event_service = nullptr;
	player_service = nullptr;
	time_service = nullptr;
}
