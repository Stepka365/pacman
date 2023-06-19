#pragma once

#include "../i_state+exit.h"
#include "../i_window_keeper.h"
#include "menu.h"

#include <SFML/Audio.hpp>

class SelectState : public IState, public IWindowKeeper {
public:
    SelectState(IStateManager& state_manager, const sf::VideoMode& mode,
                const std::string& window_title);
    bool do_step() override;
private:
    void event_handling() override;
    void update() override;
    void render() override;
    void music_play_pause();
private:
    Menu m_menu;
    sf::Music m_music;
};
