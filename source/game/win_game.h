#pragma once

#include "i_game_event.h"

class WinGame : public IGameEvent {
public:
    void handle(GameContext& context) override {
        context.state = GameContext::WIN;
        GameContext::win_sound.play();
    }
};
