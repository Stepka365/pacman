#pragma once

#include "i_game_event.h"

class LostGame : public IGameEvent {
public:
    void handle(GameContext& context) override { context.state = GameContext::LOST; }
};