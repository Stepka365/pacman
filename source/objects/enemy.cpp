#include "enemy.h"
#include "../configuration.h"

#include <random>

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
        try_to_move();
        std::mt19937 gen{std::random_device{}()};
        std::normal_distribution<float> time{config::ACTION_MEAN, config::ACTION_STDDEV};
        m_time_before_action = time(gen);
    }
}

void Enemy::try_to_move() {
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution number{0, 3};
    auto target = Room::Direction(number(gen));

    auto target_side = m_location->get_side(target);
    target_side->enter(*this);
}