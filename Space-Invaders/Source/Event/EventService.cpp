#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Event\EventService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Event
{
	using namespace Global;

	EventService::EventService()
	{
		game_window = nullptr;
	}

	EventService::~EventService() = default;

	void EventService::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow(); 
	}

	bool EventService::isGameWindowOpen()
	{
		return game_window != nullptr;
	}

	bool EventService::pressedEscKey()
	{
		return game_event.key.code == sf::Keyboard::Escape;
	}

	bool EventService::pressedLeftKey()
	{
		return game_event.key.code == sf::Keyboard::Left;
	}

	bool EventService::pressedRightKey()
	{
		return game_event.key.code == sf::Keyboard::Right;
	}

	bool EventService::isKeyboardEvent()
	{
		return game_event.type == sf::Event::KeyPressed;
	}

	bool EventService::pressedLeftMouseButton()
	{
		return game_event.type == sf::Event::MouseButtonPressed && game_event.mouseButton.button == sf::Mouse::Left; 
	}

	bool EventService::pressedRightMouseButton()
	{
		return game_event.type == sf::Event::MouseButtonPressed && game_event.mouseButton.button == sf::Mouse::Right; 
	}

	bool EventService::gameWindowWasClosed()
	{
		return game_event.type == sf::Event::Closed;
	}

	bool EventService::hasQuitGame()
	{
		return (isKeyboardEvent() && pressedEscKey());
	}

	void EventService::update()
	{
	}

	void EventService::processEvents()
	{
		if (isGameWindowOpen()) {
			while (game_window->pollEvent(game_event)) {
				// Check for window closure
				if (gameWindowWasClosed() || hasQuitGame())
				{
					game_window->close();
				}
			}
		}
	}

}




