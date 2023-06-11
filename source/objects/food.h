#pragma once

#include "i_static_entity.h"
#include "../configuration.h"

class Food : public IStaticEntity {
    void draw_into(sf::RenderWindow& window) override {

    }
    std::unique_ptr<IStaticEntity> clone() override { return std::make_unique<Food>(*this); }
private:
    void prepare_to_draw(){
        //m_location->get_size()
    }
private:
    sf::CircleShape triangle;
    sf::Texture skin;
};