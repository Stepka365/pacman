#pragma once

#include "../maze/room.h"

class IEntity : public IMyDrawable {
public:
    void set_location(Room* room) { m_location = room; }
    Room* get_location() const { return m_location; }
protected:
    Room* m_location;
};

class MyTexture {
public:
    MyTexture(const std::string& file_name) {
        if (!m_texture.loadFromFile(file_name)) {
            throw std::runtime_error("No such file in directory");
        }
    }
    const sf::Texture& get_texture() const { return m_texture; }
private:
    sf::Texture m_texture;
};