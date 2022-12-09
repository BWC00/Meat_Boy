//
// Created by student on 1/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_GAME_H //maak onderscheid tussen view en logic?
#define INC_2022_PROJECT_BWC00_GAME_H


#include <memory>
#include <SFML/Graphics.hpp>
#include "StateManager.h"

namespace view {
    class Game{
    public:
        explicit Game(int windowWidth=1200, int windowHeight=1800);
        ~Game()=default;
    private:
//        void reset();
        void run();
        void Display();
        void clearWindow();
        static void Sleep();
        void createWindow(int width, int height);
        void createManager();
        void handleInput();
        bool _running;
        std::shared_ptr<sf::RenderWindow> _window;
        std::shared_ptr<view::StateManager> _stateManager;
//        sf::Event _event;
//        sf::Image _icon;
    };
}


#endif //INC_2022_PROJECT_BWC00_GAME_H
