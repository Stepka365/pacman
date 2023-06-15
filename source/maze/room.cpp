#include "room.h"

void Room::draw_into(sf::RenderWindow& window) {
    window.draw(m_rectangle);
    for (const auto& side: m_sides) {
        side->draw_into(window);
    }
}

void Room::set_side(Room::Direction side, std::unique_ptr<IRoomSide>&& ptr_room_side) {
    m_sides[side] = std::move(ptr_room_side);
}
Room::Direction Room::get_direction(IRoomSide* ptr_room_side) const {
    for (int i = 0; i < 4; ++i) {
        if (ptr_room_side == m_sides[i].get()) { return Direction(i); }
    }
    return INVALID;
}
