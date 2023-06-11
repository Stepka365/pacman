#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace config {
    const size_t FRAMERATE_LIMIT = 60;
    // Select Window
    const std::string SELECT_WINDOW_TITLE{"Select level"};
    const sf::VideoMode SELECT_WINDOW_SIZE{400, 600};
    //Game
    const sf::VideoMode GAME_WINDOW_SIZE{800, 600};
    const std::string GAME_WINDOW_NAME_EASY{"Pacman easy"};
    const std::string GAME_WINDOW_NAME_MEDIUM{"Pacman medium"};
    const std::string GAME_WINDOW_NAME_HARD{"Pacman hard"};
    const sf::Color WALL_COLOR{0, 255, 0};
    const float ROOM_SIZE = 50;
    // Food
    const std::string FOOD_FILE{"yum.png"};
    const float FOOD_SIZE = ROOM_SIZE * 0.3;
    const size_t FOOD_POINT_COUNT = 3;
    const sf::Color FOOD_COLOR{232, 103, 120};
    const int FOOD_OUTLINE_THICKNESS = -1;
    //Enemy
    const std::string ENEMY_FILE{"crazy.png"};
    const float ENEMY_SIZE = ROOM_SIZE * 0.6;
    const size_t ENEMY_POINT_COUNT = 5;
    const sf::Color ENEMY_COLOR{116, 33, 134};
    const int ENEMY_OUTLINE_THICKNESS = -2;
    const float ACTION_MEAN = 0.6;
    const float ACTION_STDDEV = 0.2;
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