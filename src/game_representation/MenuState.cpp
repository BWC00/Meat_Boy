//
// Created by student on 8/12/22.
//

#include "MenuState.h"
#include "CONSTANTS.h"
#include "Data.h"
#include "LevelState.h"
#include "LevelsContext.h"
#include "Window.h"
#include <algorithm>
#include <iostream>
#include <string>

view::MenuState::MenuState() : prevKey("none") {
    _background = std::make_unique<sf::Sprite>();
    _background->setTexture(view::Data::string2Texture[view::constants::MENU_BACKGROUND_TEXTURE_NAME]);
}

void view::MenuState::handleInput(logic::EVENT i, bool firstKey) {
    if (i == logic::EVENT::EXIT) {
        prevKey = "exit";
    } else if (i == logic::EVENT::ESC) {
        prevKey = "exit";
    } else if (i == logic::EVENT::NONE) {
        draw();
        prevKey = "none";
    } else if (i == logic::EVENT::RIGHT) {
        draw();
        prevKey = "right";
    } else if (i == logic::EVENT::LEFT) {
        draw();
        prevKey = "left";
    } else if (i == logic::EVENT::UP) {
        if (prevKey != "up") {
            view::LevelsContext::goPrevLevel();
            prevKey = "up";
        }
        draw();
    } else if (i == logic::EVENT::DOWN) {
        if (prevKey != "down") {
            view::LevelsContext::goNextLevel();
            prevKey = "down";
        }
        draw();
    } else if (i == logic::EVENT::SPACE) {
        draw();
        prevKey = "space";
    } else if (i == logic::EVENT::ENTER) {
        _stateManager.lock()->changeState(std::make_unique<view::LevelState>());
        prevKey = "enter";
    }
}

void view::MenuState::draw() {
    view::Window::getWindow()->draw(*_background);
    view::LevelsContext::drawMenu();
}
