#include <SFML/Graphics.hpp>
#include "../lib/snake/snake.h"
#include "../lib/apple/apple.h"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Clock.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML via FetchContent");
    sf::RectangleShape rec({40,40});
    rec.setFillColor(sf::Color::Green);
    Snake snake;
    sf::Clock timer;
    float time = 0.1f;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        snake.ShowSnake(window);
        // window.draw(rec);
        if (timer.getElapsedTime().asSeconds() >= time) {
          snake.MakeMove();
          timer.restart();
        }
        window.display();
    }

    return 0;
}