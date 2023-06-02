#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace config {
    // Select Window
    const std::string SELECT_WINDOW_TITLE{"Select level"};
    const sf::VideoMode SELECT_WINDOW_SIZE{400, 600};
    //Game
    const sf::VideoMode GAME_WINDOW_SIZE{800, 600};
    const std::string GAME_WINDOW_NAME_EASY{"Pacman easy"};
    const std::string GAME_WINDOW_NAME_MEDIUM{"Pacman medium"};
    const std::string GAME_WINDOW_NAME_HARD{"Pacman hard"};
    // Button
    const sf::Vector2f BUTTON_SIZE{250, 100};
    const size_t BUTTON_FONT_SIZE = static_cast<size_t>(BUTTON_SIZE.y / 2.0f);
    const std::string FONT_FILE{"kozuka-mincho.otf"};
    const std::string BUTTON_TEXT_EXIT{"Exit"};
    const sf::Color BUTTON_COLOR_FILL{20, 20, 20};
    const sf::Color BUTTON_COLOR_SELECTION{50, 50, 100};
    const sf::Color BUTTON_COLOR_OUTLINE{0, 0, 255};
    const int BUTTON_OUTLINE_THICKNESS = 2;

    const std::string BUTTON_TEXT_EASY{"Easy"};
    const std::string BUTTON_TEXT_MEDIUM{"Medium"};
    const std::string BUTTON_TEXT_HARD{"Hard"};
}