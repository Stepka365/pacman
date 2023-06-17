#pragma once

#include "i_entity.h"
#include "../configuration.h"

class Pacman : public IEntity {
public:
    Pacman();
    void draw_into(sf::RenderWindow& window) override;
    void move(Room::Direction direction) { m_location->get_side(direction)->enter(*this); }
private:
    sf::CircleShape m_polygon;
    inline static MyTexture m_skin{config::PACMAN_FILE};
};
