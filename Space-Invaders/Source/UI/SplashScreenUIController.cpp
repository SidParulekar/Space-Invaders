#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\UI\SplashScreen\SplashScreenUIController.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Config.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Game\GameService.h"

namespace UI
{
    using namespace Global;
    using namespace UIElement;
    using namespace Game;

	namespace SplashScreen
	{
        SplashScreenUIController::SplashScreenUIController()
        {
            game_logo_view = new AnimatedImageView();
        }      

        void SplashScreenUIController::initialize()
        {
            initializeGameLogo();
            ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic(); 
        }

        void SplashScreenUIController::initializeGameLogo()
        {
            sf::Vector2f position = getLogoPosition();
            game_logo_view->initialize(Config::game_logo_texture_path, logo_width, logo_height, position);
        }

        sf::Vector2f SplashScreenUIController::getLogoPosition()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            float x_position = (game_window->getSize().x - logo_width) / 2.0f;
            float y_position = (game_window->getSize().y - logo_height) / 2.0f;

            return sf::Vector2f(x_position, y_position);
        }

        void SplashScreenUIController::update()
        {
            game_logo_view->update();
        }

        void SplashScreenUIController::fadeInAnimationCallback()
        {
            game_logo_view->playAnimation(AnimationType::FADE_OUT, logo_animation_duration, std::bind(&SplashScreenUIController::fadeOutAnimationCallback, this));
        }

        void SplashScreenUIController::fadeOutAnimationCallback()
        {
            //ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
            GameService::setGameState(GameState::MAIN_MENU);
        }

        void SplashScreenUIController::render()
        {
            game_logo_view->render();
        }       

        void SplashScreenUIController::show()
        {
            game_logo_view->playAnimation(AnimationType::FADE_IN, logo_animation_duration, std::bind(&SplashScreenUIController::fadeInAnimationCallback, this));
        }

        SplashScreenUIController::~SplashScreenUIController()
        {
            delete game_logo_view;
        }
	}
}