//
// Created by student on 8/12/22.
//

#include <dirent.h>
#include "MenuState.h"
#include <iostream>
#include <algorithm>
#include "LevelState.h"
#include <iostream>
#include <string>
#include "Data.h"
#include "Window.h"

view::MenuState::MenuState() : _currentLevel(0), MAX_LEVELS_ON_SCREEN(10), prevKey("none") {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("../Data/Levels")) != nullptr) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != nullptr) {
            if ((std::string(ent->d_name) != ".") && (std::string(ent->d_name) != "..") && (std::string(ent->d_name) != ".DS_Store")) {
                _levels.emplace_back(Level(ent->d_name));
            }
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        //return EXIT_FAILURE;
    }
    _background.setTexture(view::Data::MenuBackgroundTexture);
}


view::MenuState& view::MenuState::getInstance(const std::shared_ptr<StateManager>& context) {
    static MenuState instance;
    instance._stateManager = context;
    return instance;
}

void view::MenuState::exitKey() {
    prevKey = "exit";
}

void view::MenuState::noInput() {
    draw();
    prevKey = "none";
}

void view::MenuState::rightKey() {
    draw();
    prevKey = "right";
}

void view::MenuState::leftKey() {
    draw();
    prevKey = "left";
}

void view::MenuState::upKey() {
    if (prevKey != "up") {
        _levels[_currentLevel].getSprite().setColor(sf::Color(255,255,255,255));
        _levels[_currentLevel].getText().setFillColor(sf::Color::Black);
        _currentLevel = std::max(0,_currentLevel-1);
        prevKey = "up";
    }
    draw();
}

void view::MenuState::downKey() {
    if (prevKey != "down") {
        _levels[_currentLevel].getSprite().setColor(sf::Color(255,255,255,255));
        _levels[_currentLevel].getText().setFillColor(sf::Color::Black);
        _currentLevel = std::min(int(_levels.size()-1), _currentLevel+1);
        prevKey = "down";
    }
    draw();
}

void view::MenuState::spaceKey() {
    draw();
    prevKey = "space";
}

void view::MenuState::enterKey() {
    _stateManager->changeState(LevelState(_stateManager, _levels[_currentLevel].getName()));
    prevKey = "enter";
}

void view::MenuState::draw() {
    view::Window::getWindow()->draw(_background);
    int y = 0;
    _levels[_currentLevel].getSprite().setColor(sf::Color(255,255,255,180));
    _levels[_currentLevel].getText().setFillColor(sf::Color(200,0,0,255));
    for (int i = std::max(0,_currentLevel+1-MAX_LEVELS_ON_SCREEN); i < std::min((int)_levels.size(),MAX_LEVELS_ON_SCREEN+std::max(0,_currentLevel-MAX_LEVELS_ON_SCREEN+1)); i++) {
        _levels[i].draw(y);
        y += _levels[i].getHeight();
    }
}
