//
// Created by student on 1/12/22.
//

#include "World.h"
#include "../json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

logic::World::World(const std::shared_ptr<logic::AbstractFactory>& p, const std::string& levelName) : _factory(p) {
    _score = _factory->createScore();

    std::ifstream f("../Data/Levels/" + levelName);
    json data = json::parse(f);
    std::cout << data["auto_view"] << std::endl;
    //std::vector<std::vector<json> > map = data["auto_view"];
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
