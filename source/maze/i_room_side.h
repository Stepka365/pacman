#pragma once

#include "../i_my_drawable.h"

class IEntity;

class IRoomSide : public IMyDrawable {
public:
    virtual void enter(IEntity& entity) = 0;
};
