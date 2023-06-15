//
// Created by selya on 13.06.2023.
//

#include "simple_game_builder.h"

void SimpleGameBuilder::create_rooms() {

}
void SimpleGameBuilder::set_room_sides() {

}
void SimpleGameBuilder::create_context(float dynamic_objects_ratio) {

}
void SimpleGameBuilder::create_state(IStateManager& state_manager, const std::string& window_title) {

}
void SimpleGameBuilder::set_all_to_state() {

}
std::unique_ptr<GameState>&& SimpleGameBuilder::get_game() {
    return std::move(m_game_state);
}
