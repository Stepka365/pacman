#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class IWindowKeeper : public sf::RenderWindow {
public:
    IWindowKeeper(const sf::VideoMode& mode, const std::string& title) : m_window(mode, title) {}
protected:
    virtual void event_handling() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    sf::RenderWindow m_window;
};
