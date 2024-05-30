#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\PlayerController.h"
#include <SFML/Graphics.hpp>

class PlayerView
{
private:

    const sf::String player_texture_path = "assets/textures/player_ship.png";

    const float player_sprite_width = 60.f;
    const float player_sprite_height = 60.f;

    sf::Texture player_texture;
    sf::Sprite player_sprite;


    sf::RenderWindow* game_window;

    PlayerController* player_controller;

    void initializePlayerSprite(); // To create the player ship to be rendered in the game window
    void scalePlayerSprite(); // To set the scale of the player ship according to the specified width and height

public:

    PlayerView();
    ~PlayerView();

    void initialize(PlayerController* controller);
    void update();
    void render();

    

};