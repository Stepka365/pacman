#pragma once

#include "../configuration.h"
#include "i_state_manager.h"
#include "../select/select_state.h"

class Application : public IStateManager {
public:
    int run();
    void set_next_state(std::unique_ptr<IState>&& state) override;
    void apply_deffer_state_change();
private:
    std::unique_ptr<IState> m_ptr_state_current = std::make_unique<SelectState>
            (*this, config::SELECT_WINDOW_SIZE, config::SELECT_WINDOW_TITLE);
    std::unique_ptr<IState> m_ptr_state_next;
};