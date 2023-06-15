#include "food.h"
#include "../configuration.h"

Food::Food() : m_polygon(config::FOOD_SIZE, config::FOOD_POINT_COUNT) {
    m_polygon.setOrigin(m_polygon.getRadius(), m_polygon.getRadius());
    if (!m_skin.loadFromFile(config::FOOD_FILE)) {
        throw std::runtime_error("No such file in directory");
    }
    m_polygon.setTexture(&m_skin);
    m_polygon.setOutlineThickness(config::FOOD_OUTLINE_THICKNESS);
    m_polygon.setOutlineColor(config::FOOD_COLOR);
}
