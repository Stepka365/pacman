#pragma once

#include "i_visitor.h"
#include "../configuration.h"

class Pacman : public IEntity, public IVisitor {
public:
    Pacman();
    void draw_into(sf::RenderWindow& window) override;
    void move(Room::Direction direction) { m_location->get_side(direction)->enter(*this); }
    std::unique_ptr<IGameEvent> visit(Enemy& enemy) override;
    std::unique_ptr<IGameEvent> visit(Food& food) override;
private:
    sf::CircleShape m_polygon;
    inline static MyTexture m_skin{config::PACMAN_FILE};
};
