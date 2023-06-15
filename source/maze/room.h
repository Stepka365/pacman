#pragma once

#include "i_room_side.h"

class Room : public IMyDrawable {
public:
    enum Direction { INVALID = -1, LEFT, RIGHT, UP, DOWN };

    Room(float size) : m_rectangle({size, size}) {}
    void draw_into(sf::RenderWindow& window) override;

    void set_side(Direction side, std::unique_ptr<IRoomSide>&& ptr_room_side);
    void set_position(const sf::Vector2f& position) { m_rectangle.setPosition(position); }
    float get_size() const { return m_rectangle.getSize().x; }
    const sf::Vector2f& get_position() { return m_rectangle.getPosition(); }
    IRoomSide* get_side(Direction side) const { return m_sides[side].get(); }
    Direction get_direction(IRoomSide* ptr_room_side) const;
private:
    sf::RectangleShape m_rectangle;
    std::array<std::unique_ptr<IRoomSide>, 4> m_sides;
};
