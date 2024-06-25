#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\GameplayUI\GameplayUIController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Config.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Player\PlayerModel.h"

namespace UI
{
	namespace GameplayUI
	{
		using namespace Global;
        using namespace UI::UIElement;

        GameplayUIController::GameplayUIController() 
        { 
            createUIElements(); 
        }

        void GameplayUIController::createUIElements()
        {
            player_image = new ImageView();

            enemies_killed_text = new TextView();
        }

        void GameplayUIController::initialize()
        {
            initializeImage();
            initializeText();
        }

        void GameplayUIController::initializeImage()
        {
            player_image->initialize(Config::player_texture_path, player_sprite_width, player_sprite_height, sf::Vector2f(0, 0));
        }

        void GameplayUIController::initializeText()
        {

            sf::String enemies_killed_string = "Enemies Killed  :  0";


            enemies_killed_text->initialize(enemies_killed_string, sf::Vector2f(enemies_killed_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, text_color);
        }

        void GameplayUIController::update()
        {
            updateEnemiesKilledText();
        }

        void GameplayUIController::updateEnemiesKilledText()
        {
            sf::String enemies_killed_string = "Enemies Killed  :  " + std::to_string(PlayerModel::enemies_killed);
            enemies_killed_text->setText(enemies_killed_string);
        }

        void GameplayUIController::render()
        {

            enemies_killed_text->render();
            drawPlayerLives();
        }

        void GameplayUIController::drawPlayerLives()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            for (int i = 0; i < PlayerModel::player_lives; i++)
            {
                player_image->setPosition(sf::Vector2f(player_lives_x_offset - (i * player_lives_spacing), player_lives_y_offset));
                player_image->render();
            }
        }

        void GameplayUIController::show() { }
   
        GameplayUIController::~GameplayUIController() 
        { 
            destroy(); 
        }

        void GameplayUIController::destroy()
        {
            delete player_image;

            delete enemies_killed_text;
        }
	}
}