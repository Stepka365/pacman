#pragma once

#include "../manager/i_state_manager.h"
#include "../i_my_drawable.h"
#include "button.h"

#include <vector>

class Menu : public IMyDrawable {
public:
    Menu(IStateManager& state_manager);
    void process_mouse(const sf::Vector2f& pos, bool is_pressed);
    void draw_into(sf::RenderWindow& window) override;
private:
    std::vector<std::unique_ptr<Button>> m_buttons;
};