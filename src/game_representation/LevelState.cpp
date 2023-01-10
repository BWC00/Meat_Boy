//
// Created by student on 8/12/22.
//

#include "LevelState.h"
#include "Data.h"
#include "LevelsContext.h"
#include "MenuState.h"
#include "StateManager.h"
#include "Window.h"
#include <memory>

view::LevelState::LevelState() {
    _background = std::make_unique<sf::Sprite>();
    createWorld(view::LevelsContext::getCurrentLevelName());
    _background->setTexture(view::LevelsContext::getCurrentLevelBackgroundTexture());
}

void view::LevelState::createWorld(const std::string& levelName) {
    _world = std::make_unique<logic::World>(std::make_unique<view::ConcreteFactory>(), levelName);
}

void view::LevelState::handleInput(logic::EVENT i, bool firstKey) {
    view::Window::getWindow()->draw(*_background);
    checkIfWon(_world->update(i, firstKey));
    if (i == logic::EVENT::ESC) {
        _stateManager.lock()->changeState(std::make_unique<view::MenuState>());
    }
}

void view::LevelState::checkIfWon(bool w) {
    if (w) {
        view::LevelsContext::goNextLevel();
        _stateManager.lock()->changeState(std::make_unique<LevelState>());
    }
}
