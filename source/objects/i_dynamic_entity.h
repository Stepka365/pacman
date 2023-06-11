#pragma once

#include "i_entity.h"

class IDynamicEntity : public IEntity {
public:
    virtual void action() = 0;
    virtual std::unique_ptr<IDynamicEntity> clone() const = 0;
};
