#include "game_state.h"

bool GameState::do_step() {
    event_handling();
    update();
    render();
    return true;
}
void GameState::event_handling() {

}
void GameState::update() {

}
void GameState::render() {

}
