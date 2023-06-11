#pragma once

#include "i_room_side.h"
#include "room.h"

class Pass : public IRoomSide {
public:
    Pass(Room* room1, Room* room2) : m_room1(room1), m_room2(room2) {}
    void draw_into(sf::RenderWindow& window) override {}
private:
    Room* m_room1;
    Room* m_room2;
};