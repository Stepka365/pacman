#pragma once

#include "i_visitable.h"

class IDynamicEntity : public IEntity, public IVisitable {
public:
    virtual void action() = 0;
    virtual std::unique_ptr<IDynamicEntity> clone() const = 0;
};
