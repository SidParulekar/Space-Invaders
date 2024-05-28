#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h";

ServiceLocator::ServiceLocator()
{
	graphic_service = nullptr;
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
	graphic_service = new GraphicService;
}

//deletes service instances and deallocates memory
void ServiceLocator::clearAllServices()
{
	delete graphic_service;
	graphic_service = nullptr;
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
}

//updates services
void ServiceLocator::update()
{
	graphic_service->update();
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
