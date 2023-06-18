#pragma once

#include "i_entity.h"
#include "i_static_entity.h"

#include <list>

class IVisitor {
public:
    virtual std::unique_ptr<IGameEvent> visit(Food& food) = 0;
    virtual std::unique_ptr<IGameEvent> visit(Enemy& enemy) = 0;
    virtual ~IVisitor() = default;
};