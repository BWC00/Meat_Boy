//
// Created by student on 8/12/22.
//

#include "StateManager.h"
#include "MenuState.h"

view::StateManager::StateManager() {
    _state = std::make_shared<view::MenuState>();
}

void view::StateManager::createFactory() {
    _factory = std::make_shared<view::ConcreteFactory>(_window);
}

void view::StateManager::createWorld() {
    _world = std::make_unique<logic::World>(_factory);
}

void view::StateManager::Update(){
    _world->update(_input);
}

void view::StateManager::handleInput(logic::INPUT input) {
    _state->handleInput(input);
}