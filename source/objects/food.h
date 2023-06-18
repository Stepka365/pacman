#pragma once

#include "i_static_entity.h"
#include "../configuration.h"

class Food : public IStaticEntity {
public:
    Food();
    void draw_into(sf::RenderWindow& window) override;
    std::unique_ptr<IStaticEntity> clone() const override { return std::make_unique<Food>(*this); }
    std::unique_ptr<IGameEvent> accept(IVisitor& visitor) override;

private:
    sf::CircleShape m_polygon;
    inline static MyTexture m_skin{config::FOOD_FILE};
};
