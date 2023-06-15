#pragma once

#include "room.h"

class Wall : public IRoomSide {
public:
    Wall(Room& room) : m_room(room) {}
    void draw_into(sf::RenderWindow& window) override;
    void enter(IEntity& entity) override {}

private:
    void prepare_to_draw();

private:
    Room& m_room;
    std::array<sf::Vertex, 2> m_line;
};
