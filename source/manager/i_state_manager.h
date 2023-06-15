#pragma once

#include "../i_state+exit.h"

#include <memory>

class IStateManager {
public:
    virtual void set_next_state(std::unique_ptr<IState>&& state) = 0;
    virtual ~IStateManager() = default;
};
