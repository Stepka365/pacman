#pragma once

#include "../objects/game_context.h"

class IGameEvent{
public:
    virtual void handle(GameContext& context) = 0;
    virtual ~IGameEvent() = default;
};