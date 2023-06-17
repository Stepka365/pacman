#include "maze.h"

void Maze::draw_into(sf::RenderWindow& window) {
    for (const auto& line: m_rooms) {
        for (const auto& room: line) {
            room->draw_into(window);
        }
    }
}
