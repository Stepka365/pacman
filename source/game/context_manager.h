#pragma once

#include "../objects/game_context.h"

#include <stack>

class ContextManager {
public:
    void set_context(GameContext&& context) { m_context = std::move(context); }
    GameContext& get_context() { return m_context; }
    void save_current_context() { m_history.push(m_context.clone()); }
    void restore_previous_context();
private:
    GameContext m_context;
    std::stack<GameContext> m_history;
};