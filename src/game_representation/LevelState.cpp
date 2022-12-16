//
// Created by student on 8/12/22.
//

#include "LevelState.h"
#include "../logic_library/INPUT.h"
#include <memory>

view::LevelState::LevelState(const std::shared_ptr<StateManager>& context, const std::string& levelName) : State(context) {
    createFactory();
    createWorld(levelName);
}
void view::LevelState::createFactory() {
    _factory = std::make_shared<view::ConcreteFactory>();
}

void view::LevelState::createWorld(const std::string& levelName) {
    _world = std::make_unique<logic::World>(_factory, levelName);
}

void view::LevelState::exitKey() {
	_world->update(logic::INPUT::EXIT);
}

void view::LevelState::noInput() {
	_world->update(logic::INPUT::NONE);
}

void view::LevelState::rightKey() {
	_world->update(logic::INPUT::RIGHT);
}

void view::LevelState::leftKey() {
	_world->update(logic::INPUT::LEFT);
}

void view::LevelState::upKey() {
	_world->update(logic::INPUT::UP);
}

void view::LevelState::downKey() {
	_world->update(logic::INPUT::DOWN);
}

void view::LevelState::spaceKey() {
	_world->update(logic::INPUT::SPACE);
}

void view::LevelState::enterKey() {
	_world->update(logic::INPUT::ENTER);
}
