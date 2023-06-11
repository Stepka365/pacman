#pragma once

#include "../i_state+exit.h"
#include "../i_window_keeper.h"
#include "../maze/maze.h"
#include "context_manager.h"

class GameState : public IState, public IWindowKeeper {
public:
    GameState(IStateManager& state_manager,
              const sf::VideoMode& mode,
              const std::string& window_title) :
            IState(state_manager), IWindowKeeper(mode, window_title) {}
    bool do_step() override;
    //void set_maze(Maze& maze) { m_maze = maze; }
private:
    void event_handling() override;
    void update() override;
    void render() override;
    Maze m_maze;
    ContextManager m_context_manager;
};