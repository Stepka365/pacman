#pragma once

class IStateManager;

class IState {
public:
    IState(IStateManager& state_manager) : m_state_manager(state_manager) {}
    virtual ~IState() = default;
    virtual bool do_step() = 0;
protected:
    IStateManager& m_state_manager;
};

class ExitState : public IState {
public:
    using IState::IState;
    bool do_step() override { return false; }
};
