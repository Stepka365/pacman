#pragma once

#include "../i_my_drawable.h"

class IEntity;

class IRoomSide : public IMyDrawable {
public:
    virtual void enter(const IEntity& entity) = 0;
};