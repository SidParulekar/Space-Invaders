#include <iostream>
#include <SFML/Graphics.hpp>
#include "Header\GameService.h"

using namespace std;

int main()
{

    GameService* game_service = new GameService(); 

    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }

    delete game_service;


    /*sf::VideoMode videoMode = sf::VideoMode(800, 600);


    sf::RenderWindow window(videoMode, "SFML Window");

    Player player;

    player.player_texture.loadFromFile("assets/textures/player_ship.png");

    player.player_sprite.setTexture(player.player_texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
        {

            player.move(-1.0f * player.GetMoveSpeed()); 

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        {
             
            player.move(1.0f * player.GetMoveSpeed()); 
             
        }

        window.clear(sf::Color::Blue);

        player.player_sprite.setPosition(player.getPosition());

        window.draw(player.player_sprite);

        window.display();
    }*/

    return 0;
}