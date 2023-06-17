#include "game_context.h"

GameContext GameContext::clone() const {
    GameContext clone_context;
    clone_context.state = state;
    clone_context.pacman = pacman;
    for (const auto& elem: dynamic_objects) {
        clone_context.dynamic_objects.emplace_back(elem->clone());
    }
    for (const auto& elem: static_objects) {
        clone_context.static_objects.emplace_back(elem->clone());
    }
    return clone_context;
}
