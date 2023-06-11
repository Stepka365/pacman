#pragma once

#include "i_dynamic_entity.h"
#include "i_static_entity.h"
#include "pacman.h"

class GameContext {
public:
    GameContext clone();

    enum State { INGAME, WIN, LOST } state = INGAME;
    Pacman pacman;
    std::vector<std::unique_ptr<IDynamicEntity>> dynamic_objects;
    std::vector<std::unique_ptr<IStaticEntity>> static_objects;
};