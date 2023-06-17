#include "game_builder_director.h"

std::unique_ptr<GameState> GameBuilderDirector::build(IStateManager& state_manager) {
    m_ptr_builder->create_rooms();
    m_ptr_builder->set_room_sides();
    m_ptr_builder->create_context(m_dynamic_objects_ratio);
    m_ptr_builder->create_state(state_manager, m_window_title);
    m_ptr_builder->set_all_to_state();
    return m_ptr_builder->get_game();
}
