#pragma once

#include "../i_my_drawable.h"
#include "../command/i_select_command.h"

class Button : public IMyDrawable {
public:
    Button(const sf::Vector2f& button_center_pos,
           const sf::Vector2f& button_size,
           const std::string& text,
           const size_t font_size,
           std::unique_ptr<ISelectCommand>&& ptr_command);
    void select();
    void unselect();
    bool is_selected() const { return m_is_selected; }
    bool is_position_in(const sf::Vector2f& pos);
    void push() { m_ptr_command->execute(); }
    void draw_into(sf::RenderWindow& window) override;
private:
    std::unique_ptr<ISelectCommand> m_ptr_command;
    bool m_is_selected = false;
    sf::Font m_font;
    sf::Text m_text;
    sf::RectangleShape m_rectangle;
};
