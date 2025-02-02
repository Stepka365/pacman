#include "context_manager.h"

void ContextManager::restore_previous_context() {
    if (m_history.size() == 1) {
        m_context = m_history.top().clone();
        return;
    }
    m_context = std::move(m_history.top());
    m_history.pop();
}
