#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\UI\ImageView.h"
#include <SFML/Graphics.hpp>

namespace Player
{
    class PlayerController;

    class PlayerView
    {
    private: 

        const float player_sprite_width = 60.f;
        const float player_sprite_height = 60.f;      

        PlayerController* player_controller;

        UI::UIElement::ImageView* player_image;

        void createPlayerImage();
        void initializePlayerImage();
        sf::String getPlayerTexturePath();

    public:

        PlayerView();
        ~PlayerView();

        void initialize(PlayerController* controller);
        void update();
        void render();

        const sf::Sprite& getPlayerSprite();

    };
}

