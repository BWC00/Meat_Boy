//
// Created by student on 1/12/22.
//

#include "World.h"

logic::World::World(const std::shared_ptr<logic::AbstractFactory>& p) : _factory(p) {
    _view = _factory->createCamera();
    _score = _factory->createScore();
}

void logic::World::reset() {

}

void logic::World::update(INPUT input) {

}

bool logic::World::collisionWithPlayer(const std::shared_ptr<logic::EntityModel> &object) const {
    return false;
}

void logic::World::tick() {

}

void logic::World::exit() {

}
