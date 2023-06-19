#pragma once

#include "i_dynamic_entity.h"
#include "i_static_entity.h"
#include "pacman.h"

#include <SFML/Audio.hpp>
#include <list>

class MyMusic {
public:
    MyMusic(const std::string& file_name) { m_sound.openFromFile(file_name); }
    void play() { m_sound.play(); }
private:
    sf::Music m_sound;
};

class GameContext {
public:
    GameContext clone() const;

    enum State { INGAME, WIN, LOST } state = INGAME;
    Pacman pacman;
    std::list<std::unique_ptr<IDynamicEntity>> dynamic_objects;
    std::list<std::unique_ptr<IStaticEntity>> static_objects;
    inline static MyMusic lost_sound{config::GAME_LOST_SOUND};
    inline static MyMusic win_sound{config::GAME_LOST_SOUND};
};
