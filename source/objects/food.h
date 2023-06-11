#pragma once

#include "i_static_entity.h"

class Food : public IStaticEntity {
public:
    Food();
    void draw_into(sf::RenderWindow& window) override { window.draw(m_polygon); }
    std::unique_ptr<IStaticEntity> clone() override { return std::make_unique<Food>(*this); }

private:
    sf::CircleShape m_polygon;
    sf::Texture m_skin;
};
