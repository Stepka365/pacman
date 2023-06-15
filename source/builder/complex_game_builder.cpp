//
// Created by selya on 13.06.2023.
//

#include "complex_game_builder.h"

void ComplexGameBuilder::create_rooms() {

}
void ComplexGameBuilder::set_room_sides() {

}
void ComplexGameBuilder::create_context(float dynamic_objects_ratio) {

}
void ComplexGameBuilder::create_state(IStateManager& state_manager, const std::string& window_title) {

}
void ComplexGameBuilder::set_all_to_state() {

}
std::unique_ptr<GameState>&& ComplexGameBuilder::get_game() {
    return std::move(m_game_state);
}
