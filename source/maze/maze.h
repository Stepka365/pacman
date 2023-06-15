#pragma once

#include "room.h"

#include <memory>

class Maze : public IMyDrawable {
public:
    Maze() = default;
    Maze(std::vector<std::shared_ptr<Room>>&& rooms) : m_rooms(std::move(rooms)) {}
    void draw_into(sf::RenderWindow& window) override;
private:
    std::vector<std::shared_ptr<Room>> m_rooms;
};
