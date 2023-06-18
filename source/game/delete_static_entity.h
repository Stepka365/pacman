#pragma once

#include "i_game_event.h"
#include "../objects/food.h"

class DeleteStaticEntity : public IGameEvent {
public:
    DeleteStaticEntity(IStaticEntity& entity) : m_entity(entity) {}
    void handle(GameContext& context) override;
private:
    IStaticEntity& m_entity;
};
