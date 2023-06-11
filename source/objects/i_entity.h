#pragma once

#include "../maze/room.h"

#include <memory>

class IEntity : public IMyDrawable {
public:
    void set_location(Room* room) { m_location.reset(room); }
    Room* get_location() const { return m_location.get(); }
protected:
    std::shared_ptr<Room> m_location;
};
