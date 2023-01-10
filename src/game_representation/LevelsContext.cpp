//
// Created by Mohammed Shakleya on 16/12/2022.
//

#include "LevelsContext.h"
#include "Data.h"
#include <algorithm>
#include <dirent.h>
#include <iostream>

view::LevelsContext::LevelsContext() {
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir("./Data/Levels")) != nullptr) {
        /* print all the files and directories within directory */
        while ((ent = readdir(dir)) != nullptr) {
            if ((std::string(ent->d_name) != ".") && (std::string(ent->d_name) != "..") &&
                (std::string(ent->d_name) != ".DS_Store")) {
                _levels.push_back(std::make_unique<view::Level>(Level(ent->d_name)));
            }
        }
        closedir(dir);
        //        std::sort(_levels.begin(),_levels.end());
    } else {
        /* could not open directory */
        perror("");
        // return EXIT_FAILURE;
    }
}

view::LevelsContext& view::LevelsContext::getInstance() {
    static LevelsContext instance;
    return instance;
}

void view::LevelsContext::goPrevLevel() { getInstance()._goPrevLevel(); }

void view::LevelsContext::_goPrevLevel() {
    _levels[_currentLevel]->getSprite()->setColor(sf::Color(255, 255, 255, 255));
    _levels[_currentLevel]->getText()->setFillColor(sf::Color::Black);
    _currentLevel = std::max(0, _currentLevel - 1);
}

void view::LevelsContext::goNextLevel() { getInstance()._goNextLevel(); }

void view::LevelsContext::_goNextLevel() {
    _levels[_currentLevel]->getSprite()->setColor(sf::Color(255, 255, 255, 255));
    _levels[_currentLevel]->getText()->setFillColor(sf::Color::Black);
    _currentLevel = (_currentLevel + 1) % _levels.size();
}

void view::LevelsContext::drawMenu() { getInstance()._drawMenu(); }

void view::LevelsContext::_drawMenu() {
    int y = 0;
    _levels[_currentLevel]->getSprite()->setColor(sf::Color(255, 255, 255, 180));
    _levels[_currentLevel]->getText()->setFillColor(sf::Color(200, 0, 0, 255));
    for (int i = std::max(0, _currentLevel + 1 - MAX_LEVELS_ON_SCREEN);
         i <
         std::min((int)_levels.size(), MAX_LEVELS_ON_SCREEN + std::max(0, _currentLevel - MAX_LEVELS_ON_SCREEN + 1));
         i++) {
        _levels[i]->draw(y);
        y += _levels[i]->getHeight();
    }
}

const std::string& view::LevelsContext::getCurrentLevelName() {
    return getInstance()._levels[getInstance()._currentLevel]->getName();
}

sf::Texture& view::LevelsContext::getCurrentLevelBackgroundTexture() {
    return view::Data::string2Texture[getInstance()._levels[getInstance()._currentLevel]->getBackgroundTextureName()];
}