#pragma once

#include "i_dynamic_entity.h"
#include "../configuration.h"

#include <random>

class Enemy : public IDynamicEntity {
public:
    Enemy();
    void draw_into(sf::RenderWindow& window) override;
    void action() override;
    std::unique_ptr<IDynamicEntity> clone() const override { return std::make_unique<Enemy>(*this); }
    std::unique_ptr<IGameEvent> accept(IVisitor& visitor) override;

private:
    inline static std::mt19937 s_gen{std::random_device{}()};
    inline static std::normal_distribution<float>
            s_rest_time{config::ACTION_MEAN, config::ACTION_STDDEV};
    inline static std::uniform_int_distribution s_side_choice{0, 3};
private:
    sf::CircleShape m_polygon;
    inline static MyTexture m_skin{config::ENEMY_FILE};
    sf::Clock m_clock;
    float m_time_before_action;
};
