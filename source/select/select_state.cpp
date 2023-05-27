#include "select_state.h"
#include "../manager/i_state_manager.h"

bool SelectState::do_step() {
    event_handling();
    update();
    render();
    return true;
}
void SelectState::event_handling() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        if (event.key.code == sf::Keyboard::Q) {
            m_state_manager.set_next_state(std::make_unique<ExitState>(m_state_manager));
        }
    }
}
void SelectState::update() {

}
void SelectState::render() {

}
