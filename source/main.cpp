#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 200), "SFML works!");
    sf::CircleShape shape{ 75 };
    shape.move(0, 25);
    shape.setFillColor(sf::Color::Blue);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        shape.move(0.01, 0);
        window.clear(sf::Color::Green);
        window.draw(shape);
        window.display();
    }
    return 0;
}
