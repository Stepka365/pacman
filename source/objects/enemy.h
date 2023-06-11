#pragma once

#include "i_dynamic_entity.h"

class Enemy : public IDynamicEntity {
public:
    Enemy();
    void draw_into(sf::RenderWindow& window) override { window.draw(m_polygon); }
    void action() override;
    std::unique_ptr<IDynamicEntity> clone() override { return std::make_unique<Enemy>(*this); }

private:
    void try_to_move();
private:
    sf::CircleShape m_polygon;
    sf::Texture m_skin;
    sf::Clock m_clock;
    float m_time_before_action;
};