#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\UI\ImageView.h"
#include <SFML/Graphics.hpp>

namespace Powerup
{
    class PowerupController;
    enum class PowerupType;

    class PowerupView
    {
    private:
        const float powerup_sprite_width = 30.f;
        const float powerup_sprite_height = 30.f;

        PowerupController* powerup_controller;
        UI::UIElement::ImageView* powerup_image;

        void createPowerupImage();
        void initializePowerupImage();
        sf::String getPowerupTexturePath();

        void destroy();


    public:
        PowerupView();
        ~PowerupView();

        void initialize(PowerupController* controller);
        void update();
        void render();

        const sf::Sprite& getPowerupSprite();
    };
}