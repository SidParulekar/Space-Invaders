#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Player
{

private:
    int health = 3;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
    int player_score = 0;
    int movement_speed = 5;

public:
    sf::Texture player_texture;
    sf::Sprite player_sprite;
   


    sf::Vector2f getPosition()
    {
        return position;
    }

    int getScore()
    {

    }

    void setScore(int newScore)
    {

    }

    int GetMoveSpeed()
    {
        return movement_speed;
    }

    void takeDamage()
    {

    }

    void move(float offsetX)
    {
        position.x += offsetX;
    }

    void shoot()
    {

    }



};


int main()
{

    sf::VideoMode videoMode = sf::VideoMode(800, 600);


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
    }
    return 0;
}