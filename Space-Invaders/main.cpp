#include <SFML/Graphics.hpp>

int main() {

    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    //sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Resizable Window", sf::Style::Resize);

    //sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], "Fullscreen Window", sf::Style::Fullscreen);

    
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();

        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(400, 350); // Set position

        sf::RectangleShape square(sf::Vector2f(70, 70)); 
        square.setFillColor(sf::Color::Red); 
        square.setPosition(200, 100); // Set position

        sf::CircleShape triangle(80,3); 
        triangle.setFillColor(sf::Color::Blue); 
        triangle.setPosition(500, 100); // Set position 

        window->draw(square);
        window->draw(triangle);
        window->draw(circle);

        sf::Texture texture;
        texture.loadFromFile("assets/textures/player_ship.png");

        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(300, 250); // Position
        sprite.setRotation(45); // Rotation in degrees
        sprite.setScale(0.7, 0.7); // Scale factor

        window->draw(sprite);

        sf::Font font; 
        font.loadFromFile("assets/fonts/bubbleBobble.ttf"); 
        sf::Text text("Welcome to Space Invaders!!", font, 50); 
        text.setFillColor(sf::Color::Cyan);
        window->draw(text);

        window->display();
    }

    return 0;
}