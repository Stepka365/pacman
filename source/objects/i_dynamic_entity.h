#pragma once

#include "i_entity.h"

class IDynamicEntity : public IEntity {
public:
    void virtual action() = 0;
    std::unique_ptr<IDynamicEntity> virtual clone() = 0;
};
