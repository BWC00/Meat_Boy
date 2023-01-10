//
// Created by student on 1/12/22.
//

#include "World.h"
#include "../json.hpp"
#include "CONSTANTS.h"
#include "Camera.h"
#include "Stopwatch.h"
#include <fstream>

using json = nlohmann::json;

logic::World::World(std::unique_ptr<logic::AbstractFactory> p, const std::string& levelName)
    : _factory(std::move(p)), autoView(false) {
    createLevel(levelName);
}

void logic::World::createLevel(const std::string& levelName) {
    std::ifstream f("./Data/Levels/" + levelName);
    json data = json::parse(f);
    if (data["auto_view"] == "true") {
        autoView = true;
    }
    std::vector<std::vector<json>> map = data["map"];
    for (int i = 0; i < map.size(); i++) {

        _walls.emplace_back(std::vector<std::shared_ptr<logic::Wall>>());

        for (int k = 0; k < map[i].size(); k++) {

            double hitboxWidth = logic::constants::MEATBOY_HITBOX_WIDTH;
            double hitboxHeight = logic::constants::MEATBOY_HITBOX_HEIGHT;

            if (map[i][k].contains("player")) {
                if (map[i][k]["player"]["type"] == "MeatBoy") {
                    hitboxWidth = logic::constants::MEATBOY_HITBOX_WIDTH;
                    hitboxHeight = logic::constants::MEATBOY_HITBOX_HEIGHT;
                }
                _player = _factory->createPlayer(-logic::constants::WINDOW_WIDTH / 2.0 + k * hitboxWidth,
                                                 (i + 1) * hitboxHeight, map[i][k]["player"]["type"],
                                                 map[i][k]["player"]["texture"]);
            } else if (map[i][k].contains("goal")) {
                if (map[i][k]["goal"]["type"] == "GirlGoal") {
                    hitboxWidth = logic::constants::GIRLGOAL_HITBOX_WIDTH;
                    hitboxHeight = logic::constants::GIRLGOAL_HITBOX_HEIGHT;
                }
                _goal = _factory->createGoal(-logic::constants::WINDOW_WIDTH / 2.0 + k * hitboxWidth,
                                             (i + 1) * hitboxHeight, map[i][k]["goal"]["type"],
                                             map[i][k]["goal"]["texture"]);

            } else if (map[i][k].contains("wall")) {
                if (map[i][k]["goal"]["type"] == "SimpleWall") {
                    hitboxWidth = logic::constants::SIMPLEWALL_HITBOX_WIDTH;
                    hitboxHeight = logic::constants::SIMPLEWALL_HITBOX_HEIGHT;
                }
            }
            _walls[i].push_back(_factory->createWall(-logic::constants::WINDOW_WIDTH / 2.0 + k * hitboxWidth,
                                                     (i + 1) * hitboxHeight, map[i][k]["wall"]["type"],
                                                     map[i][k]["wall"]["texture"]));
        }
    }
}

void logic::World::reset() {
    logic::Camera::reset();
    _player->reset();
}

bool logic::World::update(logic::EVENT input, bool firstKey) {
    if (firstKey && autoView) {
        double dt = Stopwatch::getElapsed().count() / 1000;
        logic::Camera::shiftView(logic::constants::AUTOVIEW_SHIFT_AMOUNT * dt);
    }

    bool won = _player->update(input, _walls, _goal, firstKey);

    if (_player->getPosition().second < logic::Camera::getLowerBound()) {
        reset();
    }

    logic::Camera::getCamera().update(_player);

    tick();

    return won;
}

void logic::World::tick() {
    for (int i = 0; i < _walls.size(); i++) {
        for (int k = 0; k < _walls[0].size(); k++) {
            if ((_walls[i][k]->getTexture() != "none") &&
                ((_walls[i][k]->getPosition().second - _walls[i][k]->getHitbox().second) <
                 logic::Camera::getUpperBound()) &&
                (_walls[i][k]->getPosition().second > logic::Camera::getLowerBound())) {
                _walls[i][k]->Notify(logic::EVENT::TICK);
            }
        }
    }
    if ((_goal->getPosition().second - _goal->getHitbox().second) < logic::Camera::getUpperBound()) {
        _goal->Notify(logic::EVENT::TICK);
    }
    _player->Notify(logic::EVENT::TICK);
}
