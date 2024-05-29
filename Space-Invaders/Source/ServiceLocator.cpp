#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h";

ServiceLocator::ServiceLocator()
{
	graphic_service = nullptr;
	event_service = nullptr;
	createServices();

}

//Destructor to clean up resources on object deletion
ServiceLocator::~ServiceLocator() 
{
	clearAllServices(); 
}

//creates instances of Services
void ServiceLocator::createServices()
{
	graphic_service = new GraphicService();
	event_service = new EventService();
}

//deletes service instances and deallocates memory
void ServiceLocator::clearAllServices()
{
	delete graphic_service;
	delete event_service;
	graphic_service = nullptr;
	event_service = nullptr;
}

ServiceLocator* ServiceLocator::getInstance()
{
	static ServiceLocator instance;
	return &instance;
}

//initializes service locator
void ServiceLocator::initialize()
{
	graphic_service->initialize();
	event_service->initialize(); 
}

//updates services
void ServiceLocator::update()
{
	graphic_service->update();
	event_service->update(); 
}

// renders the services
void ServiceLocator::render()
{
	graphic_service->render();
}

GraphicService* ServiceLocator::getGraphicService()
{
	return graphic_service;
}

EventService* ServiceLocator::getEventService()
{
	return event_service;
}
