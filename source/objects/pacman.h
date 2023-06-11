#pragma once

#include "i_entity.h"

class Pacman : public IEntity {
public:
    Pacman();
    void draw_into(sf::RenderWindow& window) override { window.draw(m_polygon); }
    void move(Room::Direction direction) { m_location->get_side(direction)->enter(*this); }
private:
    sf::CircleShape m_polygon;
    sf::Texture m_skin;
};