#pragma once
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\PlayerController.h"
#include <SFML/Graphics.hpp>

class PlayerService
{

private:

    PlayerController* player_controller;

public:
   
    PlayerService();
    ~PlayerService();

    void initialize();
    void update();
    void render();
   
};