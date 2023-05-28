#include "button.h"
#include "../configuration.h"

Button::Button(const sf::Vector2f& button_center_pos,
               const sf::Vector2f& button_size,
               const std::string& text,
               const size_t font_size,
               std::unique_ptr<ISelectCommand>&& ptr_command) {
    m_rectangle.setOrigin(button_size.x / 2, button_size.y / 2);
    m_rectangle.setSize(button_size);
    m_rectangle.setPosition(button_center_pos);
    m_rectangle.setFillColor(config::BUTTON_COLOR_FILL);
    m_rectangle.setOutlineColor(config::BUTTON_COLOR_OUTLINE);
    m_rectangle.setOutlineThickness(config::BUTTON_OUTLINE_THICKNESS);

    if (!m_font.loadFromFile(config::FONT_FILE)) {
        throw std::runtime_error("No such file in directory");
    }
    m_text.setFont(m_font);
    m_text.setString(text);
    m_text.setCharacterSize(font_size);
    m_text.setOrigin(m_text.getLocalBounds().width / 2, m_text.getLocalBounds().height / 2);
    m_text.setPosition(button_center_pos);

    m_ptr_command = std::move(ptr_command);
}
void Button::select() {
    m_rectangle.setFillColor(config::BUTTON_COLOR_SELECTION);
    m_is_selected = true;
}
void Button::unselect() {
    m_rectangle.setFillColor(config::BUTTON_COLOR_FILL);
    m_is_selected = false;
}
void Button::draw_into(sf::RenderWindow& window) {
    window.draw(m_rectangle);
    window.draw(m_text);
}
