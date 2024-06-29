#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\ImageView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Animations\AnimationSystemConfig.h"
#include <SFML/Graphics.hpp>

namespace Animation
{
    class AnimationSystem
    {
    private:
        AnimationSystemConfig animation_system_config;

        sf::String animation_texture_path;

        sf::Vector2f animation_position;
        UI::UIElement::ImageView* animation_image;

        void createUIElements();
        void initializeImage();

        int current_frame;
        sf::Clock clock;
        sf::Time frame_time;

    public:
        AnimationSystem(AnimationSystemConfig config, sf::String);
        ~AnimationSystem();

        void initialize(sf::Vector2f position);
        void update();
        void render();

        void destroy();
    };
}
