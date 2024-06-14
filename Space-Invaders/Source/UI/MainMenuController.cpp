#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\MainMenu\MainMenuController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Graphic\GraphicService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Event\EventService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Game\GameService.h"

namespace UI
{
	namespace MainMenu
	{
		using namespace Global; 
		using namespace Game;
		using namespace Graphic;
		using namespace Event;

		MainMenuController::MainMenuController()
		{
			game_window = nullptr;
		}

		void MainMenuController::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeBackgroundImage();
			initializeButtons();
		}
		
		void MainMenuController::initializeBackgroundImage()
		{
			if (background_texture.loadFromFile(background_texture_path))
			{
				background_sprite.setTexture(background_texture);
				scaleBackgroundImage();
			}
		}
		void MainMenuController::scaleBackgroundImage()
		{
			background_sprite.setScale(
				static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
				static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
			);
		}

		bool MainMenuController::loadButtonTexturesFromFile()
		{
			if (play_button_texture.loadFromFile(play_button_texture_path) &&
				instructions_button_texture.loadFromFile(instruction_button_texture_path) &&
				quit_button_texture.loadFromFile(quit_button_texture_path))
			{
				return true;
			}
		}
		void MainMenuController::initializeButtons()
		{
			if (loadButtonTexturesFromFile())
			{
				setButtonSprites();
				scaleAllButttons();
				positionButtons();
			}

		}
		void MainMenuController::setButtonSprites()
		{
			play_button_sprite.setTexture(play_button_texture);
			instructions_button_sprite.setTexture(instructions_button_texture);
			quit_button_sprite.setTexture(quit_button_texture);

			
		}
		void MainMenuController::scaleAllButttons()
		{
			scaleButton(&play_button_sprite);
			scaleButton(&instructions_button_sprite);
			scaleButton(&quit_button_sprite);

		}
		void MainMenuController::scaleButton(sf::Sprite* button_to_scale)
		{
			button_to_scale->setScale(
				static_cast<float>(button_width) / button_to_scale->getTexture()->getSize().x, 
				static_cast<float>(button_height) / button_to_scale->getTexture()->getSize().y 
			);
		}
		void MainMenuController::positionButtons()
		{
			float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

			play_button_sprite.setPosition({ x_position, 200.f });
			instructions_button_sprite.setPosition({ x_position, 500.f });
			quit_button_sprite.setPosition({ x_position, 800.f });
		}

		void MainMenuController::render()
		{
			game_window->draw(background_sprite);
			game_window->draw(play_button_sprite);
			game_window->draw(instructions_button_sprite);
			game_window->draw(quit_button_sprite);
		}

		sf::Sprite MainMenuController::getBackgroundSprite()
		{
			return background_sprite;
		}

		void MainMenuController::update()
		{
			processButtonInteractions();
		}

		bool MainMenuController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
		{
			EventService* event_service = ServiceLocator::getInstance()->getEventService();
			return event_service->pressedLeftMouseButton() && button_sprite->getGlobalBounds().contains(mouse_position);
		}

		void MainMenuController::processButtonInteractions()
		{
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window)); 

			if (clickedButton(&play_button_sprite, mouse_position)) 
			{
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK); //play button sound
				ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic(); //play background music
				GameService::setGameState(GameState::GAMEPLAY); 
			}

			if (clickedButton(&instructions_button_sprite, mouse_position)) 
			{
				printf("Clicked Instruction Button \\n");
			}

			if (clickedButton(&quit_button_sprite, mouse_position)) 
				game_window->close(); 
		}
	}
}


