#include "select_state.h"

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
            m_state_manager.set_next_state(std::make_unique<ExitState>(m_state_manager));
        }
    }
}
void SelectState::update() {
    m_menu.process_mouse(sf::Vector2f(sf::Mouse::getPosition(m_window)),
                         sf::Mouse::isButtonPressed(sf::Mouse::Left));
}
void SelectState::render() {
    m_window.clear();
    m_menu.draw_into(m_window);
    m_window.display();
}
