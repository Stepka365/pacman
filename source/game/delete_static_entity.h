#pragma once

#include "i_game_event.h"

class DeleteStaticEntity : public IGameEvent {
public:
    DeleteStaticEntity(std::list<std::unique_ptr<IStaticEntity>>::iterator& it) : m_it(it) {}
    void handle(GameContext& context) override { context.static_objects.erase(m_it); }
private:
    std::list<std::unique_ptr<IStaticEntity>>::iterator& m_it;
};