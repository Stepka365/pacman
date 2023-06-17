#include "food.h"

Food::Food() : m_polygon(config::FOOD_SIZE, config::FOOD_POINT_COUNT) {
    m_polygon.setOrigin(m_polygon.getRadius(), m_polygon.getRadius());
    m_polygon.setTexture(&m_skin.get_texture());
    m_polygon.setOutlineThickness(config::FOOD_OUTLINE_THICKNESS);
    m_polygon.setOutlineColor(config::FOOD_COLOR);
}

void Food::draw_into(sf::RenderWindow& window) {
    auto room_size = get_location()->get_size();
    auto room_pos = get_location()->get_position();
    m_polygon.setPosition(room_pos.x + room_size / 2, room_pos.y + room_size / 2);
    window.draw(m_polygon);
}
