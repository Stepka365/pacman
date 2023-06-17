#include "game_state.h"
#include "../select/select_state.h"
#include "lost_game.h"
#include "win_game.h"
#include "delete_static_entity.h"

bool GameState::do_step() {
    event_handling();
    if (m_context_manager.get_context().state == GameContext::INGAME) {
        update();
        process_all_events();
    }
    render();
    return true;
}
void GameState::event_handling() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_state_manager.set_next_state(
                    std::make_unique<SelectState>(m_state_manager,
                                                  config::SELECT_WINDOW_SIZE,
                                                  config::SELECT_WINDOW_TITLE));
        }
        if (event.type == sf::Event::KeyPressed &&
            event.key.control &&
            event.key.code == sf::Keyboard::Z) {
            m_context_manager.restore_previous_context();
        }
        if (event.type == sf::Event::KeyPressed &&
            m_context_manager.get_context().state == GameContext::INGAME) {
            process_key_pressed(event.key.code);
        }
    }
}
void GameState::update() {
    std::for_each(m_context_manager.get_context().dynamic_objects.begin(),
                  m_context_manager.get_context().dynamic_objects.end(),
                  [](auto& elem) { elem->action(); });
    for (auto& elem: m_context_manager.get_context().dynamic_objects) {
        if (elem->get_location() == m_context_manager.get_context().pacman.get_location()) {
            process_event(std::make_unique<LostGame>());
            return;
        }
    }
    for (auto it = m_context_manager.get_context().static_objects.begin();
         it != m_context_manager.get_context().static_objects.end(); ++it) {
        if ((*it)->get_location() == m_context_manager.get_context().pacman.get_location()) {
            process_event(std::make_unique<DeleteStaticEntity>(it));
        }
    }
    if (m_context_manager.get_context().static_objects.empty()) {
        process_event(std::make_unique<WinGame>());
    }
}

void GameState::render() {
    m_window.clear(m_bg_color.at(m_context_manager.get_context().state));
    m_maze.draw_into(m_window);

    for (auto& elem: m_context_manager.get_context().static_objects) {
        elem->draw_into(m_window);
    }
    m_context_manager.get_context().pacman.draw_into(m_window);
    for (auto& elem: m_context_manager.get_context().dynamic_objects) {
        elem->draw_into(m_window);
    }

    m_window.display();
}

void GameState::set_context(GameContext&& context) {
    m_context_manager.set_context(std::move(context));
    m_context_manager.save_current_context();
}

void GameState::process_key_pressed(const sf::Keyboard::Key& code) {
    auto it = m_key_dict.find(code);
    if (it != m_key_dict.end()) {
        m_context_manager.save_current_context();
        m_context_manager.get_context().pacman.move(it->second);
    }
}

void GameState::process_event(std::unique_ptr<IGameEvent>&& event) {
    m_events.emplace_back(std::move(event));
}

void GameState::process_all_events() {
    for (auto& elem: m_events) {
        elem->handle(m_context_manager.get_context());
    }
    m_events.clear();
}
