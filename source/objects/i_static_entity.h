#pragma once

#include "i_visitable.h"

class IStaticEntity : public IEntity, public IVisitable {
public:
    virtual std::unique_ptr<IStaticEntity> clone() const = 0;
};
