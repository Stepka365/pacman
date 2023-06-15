#pragma once

#include "i_select_command.h"
#include "../manager/i_state_manager.h"

class IChangeStateCommand : public ISelectCommand {
public:
    IChangeStateCommand(IStateManager& state_manager) : m_state_manager(state_manager) {}
protected:
    IStateManager& m_state_manager;
};

class ExitCommand : public IChangeStateCommand {
public:
    using IChangeStateCommand::IChangeStateCommand;
    void execute() override {
        m_state_manager.set_next_state(std::make_unique<ExitState>(m_state_manager));
    }
};
