#pragma once

#include "i_change_state_command.h"
#include "../game/game_builder_director.h"
#include "../game/game_state.h"
#include "../configuration.h"

class GameCommand : public IChangeStateCommand {
public:
    GameCommand(IStateManager& state_manager, GameBuilderDirector* ptr_director) :
            IChangeStateCommand(state_manager), m_ptr_director(ptr_director) {}
    void execute() override {
        m_state_manager.set_next_state(std::make_unique<GameState>(
                m_state_manager, config::GAME_WINDOW_SIZE, config::GAME_WINDOW_NAME_EASY));
    }
private:
    GameBuilderDirector* m_ptr_director;
};