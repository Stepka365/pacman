#pragma once

#include "i_dynamic_entity.h"
#include "../configuration.h"

#include <random>

class Enemy : public IDynamicEntity {
public:
    Enemy();
    void draw_into(sf::RenderWindow& window) override { window.draw(m_polygon); }
    void action() override;
    std::unique_ptr<IDynamicEntity> clone() const override { return std::make_unique<Enemy>(*this); }

private:
    static std::mt19937 s_gen;
    static std::normal_distribution<float> s_rest_time;
    static std::uniform_int_distribution<int> s_side_choice;
private:
    sf::CircleShape m_polygon;
    sf::Texture m_skin;
    sf::Clock m_clock;
    float m_time_before_action;
};

std::mt19937 Enemy::s_gen{std::random_device{}()};
std::normal_distribution<float> Enemy::s_rest_time{config::ACTION_MEAN, config::ACTION_STDDEV};
std::uniform_int_distribution Enemy::s_side_choice{0, 3};
