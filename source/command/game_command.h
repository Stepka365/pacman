#pragma once

#include "i_change_state_command.h"
#include "../game/game_builder_director.h"

class GameCommand : public IChangeStateCommand {
public:
    GameCommand(IStateManager& state_manager, GameBuilderDirector* ptr_director) :
            IChangeStateCommand(state_manager), m_ptr_director(ptr_director) {}
    void execute() override;
private:
    GameBuilderDirector* m_ptr_director;
};