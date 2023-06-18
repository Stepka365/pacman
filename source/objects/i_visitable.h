#pragma once

#include "i_entity.h"

class IVisitable {
public:
    virtual std::unique_ptr<IGameEvent> accept(IVisitor& visitor) = 0;
    virtual ~IVisitable() = default;
};