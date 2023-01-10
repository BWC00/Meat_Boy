//
// Created by student on 1/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_GAME_H // maak onderscheid tussen view en logic?
#define INC_2022_PROJECT_BWC00_GAME_H

#include "StateManager.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace view {
class Game {
public:
    void run();

    Game();
    ~Game() = default;

private:
    void _display();
    void _clearWindow();
    static void _sleep();
    void _createManager();
    void _handleInput();

    std::shared_ptr<view::StateManager> _stateManager;
    bool _running;
};
} // namespace view

#endif // INC_2022_PROJECT_BWC00_GAME_H
