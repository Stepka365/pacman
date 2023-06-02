#include "game_state.h"
#include "../select/select_state.h"
#include "../configuration.h"

bool GameState::do_step() {
    event_handling();
    update();
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
    }
}
void GameState::update() {

}
void GameState::render() {

}
