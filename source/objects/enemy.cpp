#include "enemy.h"

Enemy::Enemy() : m_polygon(config::ENEMY_SIZE, config::ENEMY_POINT_COUNT) {
    m_polygon.setOrigin(m_polygon.getRadius(), m_polygon.getRadius());
    m_polygon.setTexture(&m_skin.get_texture());
    m_polygon.setOutlineThickness(config::ENEMY_OUTLINE_THICKNESS);
    m_polygon.setOutlineColor(config::ENEMY_COLOR);

    m_time_before_action = s_rest_time(s_gen);
}

void Enemy::action() {
    if (m_clock.getElapsedTime().asSeconds() >= m_time_before_action) {

        auto target = Room::Direction(s_side_choice(s_gen));
        auto target_side = m_location->get_side(target);
        target_side->enter(*this);

        m_time_before_action = s_rest_time(s_gen);
        m_clock.restart();
    }
}

void Enemy::draw_into(sf::RenderWindow& window) {
    auto room_size = get_location()->get_size();
    auto room_pos = get_location()->get_position();
    m_polygon.setPosition(room_pos.x + room_size / 2, room_pos.y + room_size / 2);
    window.draw(m_polygon);
}
