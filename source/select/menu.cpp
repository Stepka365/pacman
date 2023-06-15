#include "menu.h"
#include "../configuration.h"
#include "../command/game_command.h"
#include "../builder/simple_game_builder.h"
#include "../builder/complex_game_builder.h"

Menu::Menu(IStateManager& state_manager) {
    float width = config::SELECT_WINDOW_SIZE.width;
    float height = config::SELECT_WINDOW_SIZE.height;
    m_buttons.emplace_back(std::make_unique<Button>(
            sf::Vector2f{width / 2, height / 5},
            config::BUTTON_SIZE,
            config::BUTTON_TEXT_EASY,
            config::BUTTON_FONT_SIZE,
            std::make_unique<GameCommand>(state_manager, std::make_unique<GameBuilderDirector>(
                    std::make_unique<SimpleGameBuilder>(config::GAME_WINDOW_WIDTH,
                                                        config::GAME_WINDOW_HEIGHT,
                                                        config::ROOM_SIZE),
                    config::GAME_WINDOW_NAME_EASY,
                    config::GAME_ENEMY_RATIO_EASY))));
    m_buttons.emplace_back(std::make_unique<Button>(
            sf::Vector2f{width / 2, 2 * height / 5},
            config::BUTTON_SIZE,
            config::BUTTON_TEXT_MEDIUM,
            config::BUTTON_FONT_SIZE,
            std::make_unique<GameCommand>(state_manager, std::make_unique<GameBuilderDirector>(
                    std::make_unique<SimpleGameBuilder>(config::GAME_WINDOW_WIDTH,
                                                        config::GAME_WINDOW_HEIGHT,
                                                        config::ROOM_SIZE),
                    config::GAME_WINDOW_NAME_MEDIUM,
                    config::GAME_ENEMY_RATIO_MEDIUM))));
    m_buttons.emplace_back(std::make_unique<Button>(
            sf::Vector2f{width / 2, 3 * height / 5},
            config::BUTTON_SIZE,
            config::BUTTON_TEXT_HARD,
            config::BUTTON_FONT_SIZE,
            std::make_unique<GameCommand>(state_manager, std::make_unique<GameBuilderDirector>(
                    std::make_unique<ComplexGameBuilder>(config::GAME_WINDOW_WIDTH,
                                                         config::GAME_WINDOW_HEIGHT,
                                                         config::ROOM_SIZE),
                    config::GAME_WINDOW_NAME_HARD,
                    config::GAME_ENEMY_RATIO_HARD))));
    m_buttons.emplace_back(std::make_unique<Button>(
            sf::Vector2f{width / 2, 4 * height / 5},
            config::BUTTON_SIZE,
            config::BUTTON_TEXT_EXIT,
            config::BUTTON_FONT_SIZE,
            std::make_unique<ExitCommand>(state_manager)));
}

void Menu::process_mouse(const sf::Vector2f& pos, bool is_pressed) {
    for (auto& ptr_button: m_buttons) {
        if (ptr_button->is_position_in(pos)) {
            ptr_button->select();
        }
        else {
            ptr_button->unselect();
        }
        if (ptr_button->is_selected() && is_pressed) {
            ptr_button->push();
        }
    }
}

void Menu::draw_into(sf::RenderWindow& window) {
    for (auto& ptr_button: m_buttons) {
        ptr_button->draw_into(window);
    }
}

