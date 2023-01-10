//
// Created by student on 5/12/22.
//

#include "GirlGoal.h"
#include "CONSTANTS.h"

logic::GirlGoal::GirlGoal(double x, double y, const std::string& texture) : logic::Goal(x, y, texture) {
    _hitBox = {logic::constants::GIRLGOAL_HITBOX_WIDTH, logic::constants::GIRLGOAL_HITBOX_HEIGHT};
}