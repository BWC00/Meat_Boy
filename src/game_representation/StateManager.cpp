//
// Created by student on 8/12/22.
//

#include "StateManager.h"
#include "MenuState.h"

view::StateManager::StateManager() : _state(nullptr) {}

void view::StateManager::changeState(std::unique_ptr<view::State> state) {
    _state = std::move(state);
    _state->setStateManager(shared_from_this());
}

void view::StateManager::handleInput(logic::EVENT i, bool firstKey) { _state->handleInput(i, firstKey); }