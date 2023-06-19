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
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P){
            music_play_pause();
        }
    }
}
void SelectState::update() {
    m_menu.process_mouse(m_window, sf::Mouse::isButtonPressed(sf::Mouse::Left));
}
void SelectState::render() {
    m_window.clear();
    m_menu.draw_into(m_window);
    m_window.display();
}

SelectState::SelectState(IStateManager& state_manager,
                         const sf::VideoMode& mode,
                         const std::string& window_title) :
        IState(state_manager), IWindowKeeper(mode, window_title), m_menu(state_manager) {
    m_music.openFromFile(config::SELECT_MUSIC_FILE);
    m_music.play();
    m_music.setLoop(true);
}

void SelectState::music_play_pause() {
    if (m_music.getStatus() == m_music.Playing) {
        m_music.pause();
    }
    else {
        m_music.play();
    }
}
