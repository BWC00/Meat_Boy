//
// Created by student on 5/12/22.
//

#include "EntityModel.h"

logic::EntityModel::EntityModel(double x, double y, const std::string& texture)
    : _originalPosition(x, y), _textureName(texture) {
    _position = {x, y};
}

// getters
const std::pair<double, double>& logic::EntityModel::getOriginalPosition() const { return _originalPosition; }

const std::string& logic::EntityModel::getTexture() const { return _textureName; }

const std::pair<double, double>& logic::EntityModel::getPosition() { return _position; }

const std::pair<double, double>& logic::EntityModel::getHitbox() const { return _hitBox; }

// setters
void logic::EntityModel::setPosition(double x, double y) { _position = {x, y}; }