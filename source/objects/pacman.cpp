#include "pacman.h"
#include "../configuration.h"

Pacman::Pacman() : m_polygon(config::PACMAN_SIZE) {
    m_polygon.setOrigin(m_polygon.getRadius(), m_polygon.getRadius());
    m_polygon.setPosition(m_location->get_position().x + config::ROOM_SIZE / 2,
                          m_location->get_position().y + config::ROOM_SIZE / 2);
    if (!m_skin.loadFromFile(config::PACMAN_FILE)) {
        throw std::runtime_error("No such file in directory");
    }
    m_polygon.setTexture(&m_skin);
    m_polygon.setOutlineThickness(config::PACMAN_OUTLINE_THICKNESS);
    m_polygon.setOutlineColor(config::PACMAN_COLOR);
}
