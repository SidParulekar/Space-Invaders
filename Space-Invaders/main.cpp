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

        window->clear(sf::Color::Blue);

        window->display();
    }

    return 0;
}