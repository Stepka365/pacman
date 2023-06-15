#pragma once

#include "../i_state+exit.h"
#include "../i_window_keeper.h"
#include "menu.h"

class SelectState : public IState, public IWindowKeeper {
public:
    SelectState(IStateManager& state_manager,
                const sf::VideoMode& mode,
                const std::string& window_title) :
            IState(state_manager), IWindowKeeper(mode, window_title), m_menu(state_manager) {}
    bool do_step() override;
private:
    void event_handling() override;
    void update() override;
    void render() override;
    Menu m_menu;
};
