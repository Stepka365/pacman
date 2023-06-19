#pragma once

#include "../i_state+exit.h"
#include "../i_window_keeper.h"
#include "../maze/maze.h"
#include "context_manager.h"
#include "i_game_event.h"

#include <SFML/Audio.hpp>

class GameState : public IState, public IWindowKeeper {
public:
    GameState(IStateManager& state_manager, const sf::VideoMode& mode, const std::string& window_title);

    bool do_step() override;
    void set_maze(Maze&& maze) { m_maze = std::move(maze); }
    void set_context(GameContext&& context);
    void set_music_and_play(const std::string& file_name);
    void music_play_pause();
private:
    void process_key_pressed(const sf::Keyboard::Key& code);
    void process_event(std::unique_ptr<IGameEvent>&& event);
    void process_all_events();
private:
    void event_handling() override;
    void update() override;
    void render() override;

private:
    Maze m_maze;
    ContextManager m_context_manager;
    sf::Music m_music;
    const std::unordered_map<sf::Keyboard::Key, Room::Direction> m_key_dict
            {{sf::Keyboard::W, Room::UP},
             {sf::Keyboard::A, Room::LEFT},
             {sf::Keyboard::S, Room::DOWN},
             {sf::Keyboard::D, Room::RIGHT}};
    const std::unordered_map<GameContext::State, sf::Color> m_bg_color
            {{GameContext::INGAME, config::BACKGROUND_INGAME},
             {GameContext::LOST,   config::BACKGROUND_LOST},
             {GameContext::WIN,    config::BACKGROUND_WIN}};
    std::vector<std::unique_ptr<IGameEvent>> m_events;
};
