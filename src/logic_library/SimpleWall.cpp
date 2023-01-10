//
// Created by student on 5/12/22.
//

#include "SimpleWall.h"
#include "CONSTANTS.h"

logic::SimpleWall::SimpleWall(double x, double y, const std::string& texture) : logic::Wall(x, y, texture) {
    _hitBox = {logic::constants::SIMPLEWALL_HITBOX_WIDTH, logic::constants::SIMPLEWALL_HITBOX_HEIGHT};
}