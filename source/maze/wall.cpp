#include "wall.h"
#include "../configuration.h"

void Wall::draw_into(sf::RenderWindow& window) {
    prepare_to_draw();
    window.draw(m_line.data(), m_line.size(), sf::Lines);
}

void Wall::prepare_to_draw() {
    auto pos = m_room.get_position();
    auto side = m_room.get_direction(this);
    auto len = m_room.get_size();
    if (side == Room::DOWN) {
        m_line[0].position = {pos.x, pos.y + len};
        m_line[1].position = {pos.x + len, pos.y + len};
    }
    else if (side == Room::LEFT) {
        m_line[0].position = {pos.x, pos.y};
        m_line[1].position = {pos.x, pos.y + len};
    }
    else if (side == Room::RIGHT) {
        m_line[0].position = {pos.x + len, pos.y};
        m_line[1].position = {pos.x + len, pos.y + len};
    }
    else if (side == Room::UP) {
        m_line[0].position = {pos.x, pos.y};
        m_line[1].position = {pos.x + len, pos.y};
    }
    else {
        throw std::runtime_error("Wall drawing :: invalid side");
    }
    m_line[0].color = config::WALL_COLOR;
    m_line[1].color = config::WALL_COLOR;
}

