#include "maze.h"

void Maze::draw_into(sf::RenderWindow& window) {
    for (const auto& room: m_rooms) {
        room->draw_into(window);
    }
}
