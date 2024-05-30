#pragma once
#include <SFML/Graphics.hpp>

class PlayerService
{

private:
    int health = 3;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
    int player_score = 0;
    float movement_speed = 200.0f;
    const sf::String player_texture_path = "assets/textures/player_ship.png";

    sf::Texture player_texture;
    sf::Sprite player_sprite;


    sf::RenderWindow* game_window;

    void initializePlayerSprite();
    void processPlayerInput();

public:
   
    PlayerService();
    ~PlayerService();

    void initialize();
    void update();
    void render();
   
    sf::Vector2f getPlayerPosition();
    void moveLeft();
    void moveRight();

   

};