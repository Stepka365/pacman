#pragma once

#include "../maze/room.h"

class IEntity : public IMyDrawable {
public:
    void set_location(Room* room) { m_location = room; }
    Room* get_location() const { return m_location; }
protected:
    Room* m_location;
};