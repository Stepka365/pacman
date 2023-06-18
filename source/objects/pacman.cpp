#include "pacman.h"
#include "../game/lost_game.h"
#include "../game/delete_static_entity.h"

Pacman::Pacman() : m_polygon(config::PACMAN_SIZE) {
    m_polygon.setOrigin(m_polygon.getRadius(), m_polygon.getRadius());
    m_polygon.setTexture(&m_skin.get_texture());
    m_polygon.setOutlineThickness(config::PACMAN_OUTLINE_THICKNESS);
    m_polygon.setOutlineColor(config::PACMAN_COLOR);
}

void Pacman::draw_into(sf::RenderWindow& window) {
    auto room_size = get_location()->get_size();
    auto room_pos = get_location()->get_position();
    m_polygon.setPosition(room_pos.x + room_size / 2, room_pos.y + room_size / 2);
    window.draw(m_polygon);
}

std::unique_ptr<IGameEvent> Pacman::visit(Food& food) {
    return std::make_unique<DeleteStaticEntity>(food);
}

std::unique_ptr<IGameEvent> Pacman::visit(Enemy& enemy) {
    return std::make_unique<LostGame>();
}

