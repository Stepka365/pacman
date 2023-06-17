#pragma once

#include "i_game_builder.h"

class GameBuilderDirector {
public:
    GameBuilderDirector(std::unique_ptr<IGameBuilder>&& ptr_builder,
                        const std::string& window_title,
                        float dynamic_objects_ratio)
            : m_ptr_builder(std::move(ptr_builder)),
              m_window_title(window_title),
              m_dynamic_objects_ratio(dynamic_objects_ratio) {}

    std::unique_ptr<GameState> build(IStateManager& state_manager);
private:
    std::unique_ptr<IGameBuilder> m_ptr_builder;
    std::string m_window_title;
    float m_dynamic_objects_ratio;
};
