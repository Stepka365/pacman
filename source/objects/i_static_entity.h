#pragma once

#include "i_entity.h"

class IStaticEntity : public IEntity {
public:
    std::unique_ptr<IStaticEntity> virtual clone() = 0;
};