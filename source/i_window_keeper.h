#pragma once

#include "configuration.h"

class IWindowKeeper {
public:
    IWindowKeeper(const sf::VideoMode& mode, const std::string& title) : m_window(mode, title) {
        m_window.setFramerateLimit(config::FRAMERATE_LIMIT);
    }
protected:
    virtual void event_handling() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    sf::RenderWindow m_window;
};
