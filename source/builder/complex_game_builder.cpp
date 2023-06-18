#include "complex_game_builder.h"
#include "../maze/wall.h"
#include "../maze/pass.h"
#include "../objects/enemy.h"
#include "../objects/food.h"

void ComplexGameBuilder::create_rooms() {
    int lines = m_height / m_room_size;
    int cols = m_width / m_room_size;
    float pos00x = (m_width - cols * m_room_size) / 2;
    float pos00y = (m_height - lines * m_room_size) / 2;
    for (size_t i = 0; i < lines; ++i) {
        std::vector<std::unique_ptr<Room>> cur_line;
        if (i % 2 == 0) {
            for (size_t j = 0; j < cols / 2; ++j) {
                cur_line.emplace_back(std::make_unique<Room>(m_room_size));
                cur_line[j]->set_position({pos00x + (2 * j + 1) * m_room_size,
                                           pos00y + i * m_room_size});
            }
        }
        else {
            for (size_t j = 0; j < cols; ++j) {
                cur_line.emplace_back(std::make_unique<Room>(m_room_size));
                cur_line[j]->set_position({pos00x + j * m_room_size,
                                           pos00y + i * m_room_size});
            }
        }
        m_rooms.emplace_back(std::move(cur_line));
    }
}
void ComplexGameBuilder::set_room_sides() {
    for (size_t j = 0; j < m_rooms[0].size(); ++j) {
        m_rooms[0][j]->set_side(
                Room::UP, std::make_unique<Wall>(*m_rooms[0][j]));
    }
    for (size_t i = 0; i < m_rooms.size(); ++i) {
        m_rooms[i][0]->set_side(
                Room::LEFT, std::make_unique<Wall>(*m_rooms[i][0]));
    }
    for (size_t j = 0; j < m_rooms[m_rooms.size() - 1].size(); ++j) {
        m_rooms[m_rooms.size() - 1][j]->set_side(
                Room::DOWN, std::make_unique<Wall>(*m_rooms[m_rooms.size() - 1][j]));
    }
    for (size_t i = 0; i < m_rooms.size(); ++i) {
        m_rooms[i][m_rooms[i].size() - 1]->set_side(
                Room::RIGHT, std::make_unique<Wall>(*m_rooms[i][m_rooms[i].size() - 1]));
    }
    for (size_t i = 0; i < m_rooms.size(); i += 2) {
        for (size_t j = 1; j < m_rooms[0].size(); ++j) {
            m_rooms[i][j]->set_side(Room::LEFT, std::make_unique<Wall>(*m_rooms[i][j]));
            m_rooms[i][j - 1]->set_side(Room::RIGHT, std::make_unique<Wall>(*m_rooms[i][j - 1]));
        }
    }
    for (size_t i = 1; i < m_rooms.size(); i += 2) {
        for (size_t j = 0; j < m_rooms[1].size(); j += 2) {
            m_rooms[i][j]->set_side(Room::UP, std::make_unique<Wall>(*m_rooms[i][j]));
            m_rooms[i][j]->set_side(Room::DOWN, std::make_unique<Wall>(*m_rooms[i][j]));
        }
    }
    for (size_t i = 1; i < m_rooms.size(); i += 2) {
        for (size_t j = 1; j < m_rooms[1].size(); ++j) {
            m_rooms[i][j]->set_side(
                    Room::LEFT, std::make_unique<Pass>(*m_rooms[i][j], *m_rooms[i][j - 1]));
            m_rooms[i][j - 1]->set_side(
                    Room::RIGHT, std::make_unique<Pass>(*m_rooms[i][j], *m_rooms[i][j - 1]));
        }
    }
    for (size_t i = 1; i < m_rooms.size(); i += 2) {
        for (size_t j = 1; j < m_rooms[1].size(); j += 2) {
            m_rooms[i][j]->set_side(
                    Room::UP, std::make_unique<Pass>(*m_rooms[i][j], *m_rooms[i - 1][(j - 1) / 2]));
            m_rooms[i - 1][(j - 1) / 2]->set_side(
                    Room::DOWN, std::make_unique<Pass>(*m_rooms[i][j], *m_rooms[i - 1][(j - 1) / 2]));
        }
    }
    for (size_t i = 2; i < m_rooms.size(); i += 2) {
        for (size_t j = 0; j < m_rooms[0].size(); ++j) {
            m_rooms[i][j]->set_side(
                    Room::UP, std::make_unique<Pass>(*m_rooms[i][j], *m_rooms[i - 1][2 * j + 1]));
            m_rooms[i - 1][2 * j + 1]->set_side(
                    Room::DOWN, std::make_unique<Pass>(*m_rooms[i][j], *m_rooms[i - 1][2 * j + 1]));
        }
    }
}

std::vector<std::pair<size_t, size_t>>
ComplexGameBuilder::randomize_dynamic_objects(size_t unit_num) {
    std::vector<std::pair<size_t, size_t>> coords;
    std::uniform_int_distribution<size_t> rand_line{0, m_rooms.size() - 1};
    std::uniform_int_distribution<size_t> rand_col_short{0, m_rooms[0].size() - 1};
    std::uniform_int_distribution<size_t> rand_col_long{0, m_rooms[1].size() - 1};
    auto line = rand_line(m_gen);
    coords.emplace_back(line, line % 2 ? rand_col_long(m_gen) : rand_col_short(m_gen));
    for (size_t i = 0; i < unit_num - 1; ++i) {
        line = rand_line(m_gen);
        std::pair<size_t, size_t> coord{line, line % 2 ? rand_col_long(m_gen) : rand_col_short(m_gen)};
        while (coord == coords[0]) {
            line = rand_line(m_gen);
            coord = {line, line % 2 ? rand_col_long(m_gen) : rand_col_short(m_gen)};
        }
        coords.emplace_back(std::move(coord));
    }
    return coords;
}

std::vector<std::vector<ComplexGameBuilder::Entity>>
ComplexGameBuilder::make_mask_by_coords(std::vector<std::pair<size_t, size_t>>& coords) {
    std::vector<std::vector<Entity>> mask{m_rooms.size()};
    for (size_t i = 0; i < m_rooms.size(); ++i) {
        for (size_t j = 0; j < m_rooms[i].size(); ++j) {
            mask[i].push_back(Entity::FOOD);
        }
    }
    mask[coords[0].first][coords[0].second] = Entity::PACMAN;
    for (size_t i = 1; i < coords.size(); ++i) {
        mask[coords[i].first][coords[i].second] = Entity::ENEMY;
    }
    return mask;
}

void ComplexGameBuilder::create_context(float dynamic_objects_ratio) {
    int enemies = dynamic_objects_ratio * m_rooms.size() * (m_rooms[0].size() + m_rooms[1].size()) / 2;
    auto coords = randomize_dynamic_objects(enemies + 1);
    auto mask = make_mask_by_coords(coords);
    for (size_t i = 0; i < m_rooms.size(); ++i) {
        for (size_t j = 0; j < m_rooms[i].size(); ++j) {
            if (mask[i][j] == Entity::PACMAN) {
                m_context.pacman.set_location(m_rooms[i][j].get());
            }
            else if (mask[i][j] == Entity::ENEMY) {
                auto cur_enemy = std::make_unique<Enemy>();
                cur_enemy->set_location(m_rooms[i][j].get());
                m_context.dynamic_objects.emplace_back(std::move(cur_enemy));
            }
            else {
                auto cur_food = std::make_unique<Food>();
                cur_food->set_location(m_rooms[i][j].get());
                m_context.static_objects.emplace_back(std::move(cur_food));
            }
        }
    }
}
void ComplexGameBuilder::create_state(IStateManager& state_manager, const std::string& window_title) {
    m_game_state = std::make_unique<GameState>(
            state_manager,
            sf::VideoMode{static_cast<unsigned int>(m_width), static_cast<unsigned int>(m_height)},
            window_title);
}
void ComplexGameBuilder::set_all_to_state() {
    m_game_state->set_maze(std::move(m_rooms));
    m_game_state->set_context(std::move(m_context));
}
std::unique_ptr<GameState> ComplexGameBuilder::get_game() {
    return std::move(m_game_state);
}
