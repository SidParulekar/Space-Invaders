#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\GraphicService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\EventService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\PlayerService.h"

// ServiceLocator Class Summary: This class manages access to various services in the application.

class ServiceLocator
{
private:
    // Declaring pointers to instances of different services:
    GraphicService* graphic_service;
    EventService* event_service;
    PlayerService* player_service;

    // Constructor for initializing the ServiceLocator.
    ServiceLocator();

    // Destructor for cleaning up resources upon object deletion.
    ~ServiceLocator();

    // Private Methods:
    void createServices(); 			// Creates instances of all services.
    void clearAllServices(); 		//	Deletes and deallocates memory for all services.

public:
    // Public Methods:
    static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object).

    void initialize(); 			//	Initializes the ServiceLocator.
    void update(); 				//	Updates all services.
    void render(); 				//	Renders the services.

    // Methods to Get Specific Services: 
    GraphicService* getGraphicService();   // Retrieve the GraphicService instance
    EventService* getEventService(); // Retrieve the EventService instance
    PlayerService* getPlayerService(); // Retrieve the PlayerService instance

};