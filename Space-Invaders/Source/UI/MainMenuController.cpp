#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\UI\MainMenu\MainMenuController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Event\EventService.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Game\GameService.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Config.h"

namespace UI
{
	namespace MainMenu
	{
		using namespace Global; 
		using namespace Game;
		using namespace Event;
		using namespace UIElement;

		MainMenuController::MainMenuController()
		{
			createImage();
			createButtons();
		}

		void MainMenuController::createImage()
		{
			background_image = new ImageView();
		}

		void MainMenuController::createButtons()
		{
			play_button = new ButtonView();
			instructions_button = new ButtonView();
			quit_button = new ButtonView();
		}

		void MainMenuController::initialize()
		{
			initializeBackgroundImage();
			initializeButtons();
			registerButtonCallback(); 
		}

		void MainMenuController::initializeBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			//background_image->setImageAlpha(background_alpha);
		}

		const sf::Sprite& MainMenuController::getBackgroundSprite()
		{
			return background_image->getImageSprite();
		}

		void MainMenuController::initializeButtons()
		{
			play_button->initialize("Play Button", Config::play_button_texture_path, button_width, button_height, sf::Vector2f(0, play_button_y_position));
			instructions_button->initialize("Instructions Button", Config::instruction_button_texture_path, button_width, button_height, sf::Vector2f(0, instructions_button_y_position));
			quit_button->initialize("Quit Button", Config::quit_button_texture_path, button_width, button_height, sf::Vector2f(0, quit_button_y_position));

			play_button->setCentreAlinged();
			instructions_button->setCentreAlinged();
			quit_button->setCentreAlinged();
		}

		void MainMenuController::playButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::GAMEPLAY);
		}

		void MainMenuController::instructionsButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
		}

		void MainMenuController::quitButtonCallback()
		{
			ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
		}

		void MainMenuController::registerButtonCallback()
		{
			play_button->registerCallbackFuntion(std::bind(&MainMenuController::playButtonCallback, this)); 
			instructions_button->registerCallbackFuntion(std::bind(&MainMenuController::instructionsButtonCallback, this)); 
			quit_button->registerCallbackFuntion(std::bind(&MainMenuController::quitButtonCallback, this)); 
		}

		void MainMenuController::show()
		{
			background_image->show();
			play_button->show();
			instructions_button->show();
			quit_button->show();	
		}
		
		void MainMenuController::render()
		{ 
			background_image->render(); 
			play_button->render();
			instructions_button->render(); 
			quit_button->render(); 
		}

		void MainMenuController::update()
		{
			background_image->update();
			play_button->update(); 
			instructions_button->update(); 
			quit_button->update(); 
		}

		MainMenuController::~MainMenuController()
		{
			destroy();
		}

		void MainMenuController::destroy()
		{
			delete background_image;
			delete play_button;
			delete instructions_button;
			delete quit_button;
		}		
	}
}


