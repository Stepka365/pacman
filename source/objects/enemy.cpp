#include "enemy.h"

Enemy::Enemy() : m_polygon(config::ENEMY_SIZE, config::ENEMY_POINT_COUNT) {
    m_polygon.setOrigin(m_polygon.getRadius(), m_polygon.getRadius());
    m_polygon.setPosition(m_location->get_position().x + config::ROOM_SIZE / 2,
                          m_location->get_position().y + config::ROOM_SIZE / 2);
    if (!m_skin.loadFromFile(config::ENEMY_FILE)) {
        throw std::runtime_error("No such file in directory");
    }
    m_polygon.setTexture(&m_skin);
    m_polygon.setOutlineThickness(config::ENEMY_OUTLINE_THICKNESS);
    m_polygon.setOutlineColor(config::ENEMY_COLOR);

    m_time_before_action = config::ACTION_MEAN;
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
