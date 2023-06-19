#include "delete_static_entity.h"

void DeleteStaticEntity::handle(GameContext& context) {
    for (auto it = context.static_objects.begin(); it != context.static_objects.end(); ++it) {
        if (it->get() == &m_entity) {
            context.static_objects.erase(it);
        }
    }
}