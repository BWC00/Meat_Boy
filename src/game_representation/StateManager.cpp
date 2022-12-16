//
// Created by student on 8/12/22.
//

#include "StateManager.h"
#include "MenuState.h"
#include "State.h"
#include "Window.h"

view::StateManager::StateManager() : _state(view::MenuState::getInstance(std::shared_ptr<view::StateManager>(this))) {
    view::Window::getWindow()->setKeyRepeatEnabled(false); //set to true when in levelstate mode!!!!!!!!!!11
}

void view::StateManager::changeState(const State& state) {
	_state = state;
}

void view::StateManager::exitKey() {
	_state.exitKey();
}

void view::StateManager::noInput() {
	_state.noInput();
}

void view::StateManager::rightKey() {
	_state.rightKey();
}

void view::StateManager::leftKey() {
	_state.leftKey();
}

void view::StateManager::upKey() {
	_state.upKey();
}

void view::StateManager::downKey() {
	_state.downKey();
}

void view::StateManager::spaceKey() {
	_state.spaceKey();
}

void view::StateManager::enterKey() {
	_state.enterKey();
}
