#pragma once

#include "i_entity.h"

class IStaticEntity : public IEntity {
public:
    virtual std::unique_ptr<IStaticEntity> clone() const = 0;
};
