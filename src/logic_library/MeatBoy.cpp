//
// Created by student on 5/12/22.
//

#include "MeatBoy.h"
#include "CONSTANTS.h"

logic::MeatBoy::MeatBoy(double x, double y, const std::string& texture) : logic::Player(x, y, texture) {
    _hitBox = {logic::constants::MEATBOY_HITBOX_WIDTH, logic::constants::MEATBOY_HITBOX_HEIGHT};
}