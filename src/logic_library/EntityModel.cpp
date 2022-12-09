//
// Created by student on 5/12/22.
//

#include "EntityModel.h"

logic::EntityModel::EntityModel(double x, double y) {
    setPosition(x,y);
}

const std::pair<double, double>& logic::EntityModel::getPosition() {
    return _position;
}

void logic::EntityModel::setPosition(const std::pair<double, double>& position) {
    _position = position;
}

void logic::EntityModel::setPosition(double x, double y) {
    _position.first = x;
    _position.second = y;
}

const std::pair<double, double>& logic::EntityModel::getHitbox() {
    return _hitBox;
}