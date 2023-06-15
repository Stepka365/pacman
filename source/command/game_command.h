#pragma once

#include "i_change_state_command.h"
#include "../builder/game_builder_director.h"
#include "../game/game_state.h"
#include "../configuration.h"

class GameCommand : public IChangeStateCommand {
public:
    GameCommand(IStateManager& state_manager,
                std::unique_ptr<GameBuilderDirector>&& ptr_director) :
            IChangeStateCommand(state_manager), m_ptr_director(std::move(ptr_director)) {}
    void execute() override {
        m_state_manager.set_next_state(m_ptr_director->build(m_state_manager));
    }
private:
    std::unique_ptr<GameBuilderDirector> m_ptr_director;
};
