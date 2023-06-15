#pragma once

#include "i_dynamic_entity.h"
#include "i_static_entity.h"
#include "pacman.h"

#include <list>

class GameContext {
public:
    GameContext clone();

    enum State { INGAME, WIN, LOST } state = INGAME;
    Pacman pacman;
    std::list<std::unique_ptr<IDynamicEntity>> dynamic_objects;
    std::list<std::unique_ptr<IStaticEntity>> static_objects;
};
