#include "simple_game_builder.h"
#include "../maze/wall.h"
#include "../maze/pass.h"
#include "../objects/enemy.h"
#include "../objects/food.h"

void SimpleGameBuilder::create_rooms() {
    int lines = m_height / m_room_size;
    int cols = m_width / m_room_size;
    float pos00x = (m_width - cols * m_room_size) / 2;
    float pos00y = (m_height - lines * m_room_size) / 2;
    for (size_t i = 0; i < lines; ++i) {
        std::vector<std::unique_ptr<Room>> cur_col;
        for (size_t j = 0; j < cols; ++j) {
            cur_col.emplace_back(std::make_unique<Room>(m_room_size));
            cur_col[j]->set_position({pos00x + j * m_room_size,
                                      pos00y + i * m_room_size});
        }
        m_rooms.emplace_back(std::move(cur_col));
    }
}
void SimpleGameBuilder::set_room_sides() {
    for (auto& up: m_rooms[0]) {
        up->set_side(Room::UP, std::make_unique<Wall>(*up));
    }
    for (auto& down: m_rooms[m_rooms.size() - 1]) {
        down->set_side(Room::DOWN, std::make_unique<Wall>(*down));
    }
    for (auto& line: m_rooms) {
        line[0]->set_side(Room::LEFT, std::make_unique<Wall>(*line[0]));
        line[line.size() - 1]->set_side(Room::RIGHT, std::make_unique<Wall>(*line[line.size() - 1]));
    }
    for (size_t line = 1; line <= m_rooms.size() - 1; ++line) {
        m_rooms[line][0]->set_side(
                Room::UP, std::make_unique<Pass>(*m_rooms[line][0], *m_rooms[line - 1][0]));
        m_rooms[line - 1][0]->set_side(
                Room::DOWN, std::make_unique<Pass>(*m_rooms[line][0], *m_rooms[line - 1][0]));
    }
    for (size_t col = 1; col <= m_rooms[0].size() - 1; ++col) {
        m_rooms[0][col]->set_side(
                Room::LEFT, std::make_unique<Pass>(*m_rooms[0][col], *m_rooms[0][col - 1]));
        m_rooms[0][col - 1]->set_side(
                Room::RIGHT, std::make_unique<Pass>(*m_rooms[0][col], *m_rooms[0][col - 1]));
    }
    for (size_t line = 1; line <= m_rooms.size() - 1; ++line) {
        for (size_t col = 1; col <= m_rooms[0].size() - 1; ++col) {
            m_rooms[line][col]->set_side(
                    Room::UP, std::make_unique<Pass>(*m_rooms[line][col], *m_rooms[line - 1][col]));
            m_rooms[line - 1][col]->set_side(
                    Room::DOWN, std::make_unique<Pass>(*m_rooms[line][col], *m_rooms[line - 1][col]));
            m_rooms[line][col]->set_side(
                    Room::LEFT, std::make_unique<Pass>(*m_rooms[line][col], *m_rooms[line][col - 1]));
            m_rooms[line][col - 1]->set_side(
                    Room::RIGHT, std::make_unique<Pass>(*m_rooms[line][col], *m_rooms[line][col - 1]));
        }
    }
}

std::vector<std::pair<size_t, size_t>>
SimpleGameBuilder::randomize_dynamic_objects(size_t unit_num) {
    std::vector<std::pair<size_t, size_t>> coords;
    std::uniform_int_distribution<size_t> rand_line{0, m_rooms.size() - 1};
    std::uniform_int_distribution<size_t> rand_col{0, m_rooms[0].size() - 1};
    coords.emplace_back(rand_line(m_gen), rand_col(m_gen));
    for (size_t i = 0; i < unit_num - 1; ++i) {
        std::pair<size_t, size_t> coord{rand_line(m_gen), rand_col(m_gen)};
        while (coord == coords[0]) {
            coord = {rand_line(m_gen), rand_col(m_gen)};
        }
        coords.emplace_back(std::move(coord));
    }
    return coords;
}

std::vector<std::vector<SimpleGameBuilder::Entity>>
SimpleGameBuilder::make_mask_by_coords(std::vector<std::pair<size_t, size_t>>& coords) {
    std::vector<std::vector<Entity>>
            mask{m_rooms.size(), {m_rooms[0].size(), Entity::FOOD}};
    for (auto& coord: coords) {
        mask[coord.first][coord.second] = Entity::ENEMY;
    }
    mask[coords[0].first][coords[0].second] = Entity::PACMAN;
    return mask;
}

void SimpleGameBuilder::create_context(float dynamic_objects_ratio) {
    m_context.state = GameContext::INGAME;
    int enemies = dynamic_objects_ratio * m_rooms.size() * m_rooms[0].size();
    auto coords = randomize_dynamic_objects(enemies + 1);
    auto mask = make_mask_by_coords(coords);
    for (size_t i = 0; i < m_rooms.size(); ++i) {
        for (size_t j = 0; j < m_rooms[0].size(); ++j) {
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
void SimpleGameBuilder::create_state(IStateManager& state_manager, const std::string& window_title) {
    m_game_state = std::make_unique<GameState>(
            state_manager, sf::VideoMode{(unsigned int) m_width, (unsigned int) m_height},
            window_title);
}
void SimpleGameBuilder::set_all_to_state() {
    m_game_state->set_maze(std::move(m_rooms));
    m_game_state->set_context(std::move(m_context));
}
std::unique_ptr<GameState> SimpleGameBuilder::get_game() {
    return std::move(m_game_state);
}
