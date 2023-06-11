#pragma once

#include "room.h"
#include "../objects/i_entity.h"

#include <memory>

class Pass : public IRoomSide {
public:
    Pass(Room* room1, Room* room2) : m_room1(room1), m_room2(room2) {}
    void draw_into(sf::RenderWindow& window) override {}
    void enter(IEntity& entity) override {
        entity.set_location(m_room1.get() == entity.get_location() ? m_room2.get() : m_room1.get());
    }

private:
    std::shared_ptr<Room> m_room1;
    std::shared_ptr<Room> m_room2;
};