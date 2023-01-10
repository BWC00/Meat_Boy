//
// Created by student on 5/12/22.
//

#include "Player.h"
#include "CONSTANTS.h"
#include "Goal.h"
#include "Stopwatch.h"
#include <algorithm>
#include <cmath>

logic::Player::Player(double x, double y, const std::string& texture) : logic::EntityModel(x, y, texture) { reset(); }

void logic::Player::reset() {
    _position = _originalPosition;
    _jumpHeight = logic::constants::PLAYER_JUMP_HEIGHT;
    _jumpTime = logic::constants::PLAYER_JUMP_TIME;
    _velocity = {0, 0};
    _up_collision = false;
    _down_collision = true;
    _right_collision = false;
    _left_collision = false;
    _jumped = true;
}

bool logic::Player::collisionPlayerWithEntity(const std::shared_ptr<logic::EntityModel>& entity,
                                              double& added_x_distance, double& added_y_distance) {
    bool ret = false;
    if ((_position.second + added_y_distance > entity->getPosition().second - entity->getHitbox().second + 0.001) &&
        (_position.second + added_y_distance - _hitBox.second < entity->getPosition().second - 0.001)) {

        if ((_position.first + added_x_distance + _hitBox.first > entity->getPosition().first) &&
            (_position.first + _hitBox.first < entity->getPosition().first)) {
            setPosition(entity->getPosition().first - _hitBox.first - 0.00001, _position.second);
            added_x_distance = 0;
            _right_collision = true;
            ret = true;
        }

        if ((_position.first > entity->getPosition().first + entity->getHitbox().first) &&
            (_position.first + added_x_distance < entity->getPosition().first + entity->getHitbox().first)) {
            setPosition(entity->getPosition().first + entity->getHitbox().first + 0.00001, _position.second);
            added_x_distance = 0;
            _left_collision = true;
            ret = true;
        }
    }
    if ((_position.first + added_x_distance + _hitBox.first > entity->getPosition().first) &&
        (_position.first + added_x_distance < entity->getPosition().first + entity->getHitbox().first)) {

        if ((_position.second + added_y_distance > entity->getPosition().second - entity->getHitbox().second) &&
            (_position.second < entity->getPosition().second - entity->getHitbox().second)) {
            setPosition(_position.first, entity->getPosition().second - entity->getHitbox().second - 0.00001);
            added_y_distance = 0;
            _up_collision = true;
            ret = true;
        }

        if ((_position.second + added_y_distance - _hitBox.second < entity->getPosition().second) &&
            (_position.second - _hitBox.second > entity->getPosition().second)) {
            setPosition(_position.first, entity->getPosition().second + _hitBox.second + 0.00001);
            added_y_distance = 0;
            _down_collision = true;
            ret = true;
        }
    }
    return ret;
}

bool logic::Player::update(logic::EVENT input, const std::vector<std::vector<std::shared_ptr<logic::Wall>>>& walls,
                           const std::shared_ptr<logic::Goal>& goal, bool firstKey) {

    double initial_velocity = 2 * _jumpHeight / _jumpTime;
    double g = -2 * _jumpHeight / (_jumpTime * _jumpTime);
    double dt = Stopwatch::getElapsed().count() / 1000;
    std::pair<double, double> acceleration;

    if (_down_collision && (_jumped || input == logic::EVENT::SPACE)) {
        _velocity.second = initial_velocity;
        _jumped = false;
        _down_collision = false;

    } else if (_left_collision && !_up_collision && (_jumped || input == logic::EVENT::SPACE)) {
        _velocity.second = initial_velocity;
        _jumped = false;
        _left_collision = false;
        _velocity.first = initial_velocity;

    } else if (_right_collision && !_up_collision && (_jumped || input == logic::EVENT::SPACE)) {
        _velocity.second = initial_velocity;
        _jumped = false;
        _right_collision = false;
        _velocity.first = -initial_velocity;

    } else if ((_right_collision && input == logic::EVENT::RIGHT) || (_left_collision && input == logic::EVENT::LEFT)) {
        acceleration.first = 0;
        _velocity.first = 0;

    } else {
        acceleration.first = 0;
        if (input == logic::EVENT::RIGHT) {
            acceleration.first = logic::constants::PLAYER_HORIZONTAL_ACCELERATION;
        } else if (input == logic::EVENT::LEFT) {
            acceleration.first = -logic::constants::PLAYER_HORIZONTAL_ACCELERATION;
        } else {
            _velocity.first *= pow(0.95, dt / 0.016);
        }
    }

    if (_down_collision) {
        acceleration.second = g;
        _velocity.second = 0;
    }

    if (_up_collision) {
        _velocity.second = 0;
        _up_collision = false;
    } else {
        acceleration.second = g;
    }

    std::pair<double, double> velo = {std::clamp(_velocity.first + 0.5 * acceleration.first * dt,
                                                 -logic::constants::PLAYER_HORIZONTAL_TERMINAL_VELOCITY,
                                                 logic::constants::PLAYER_HORIZONTAL_TERMINAL_VELOCITY),
                                      std::clamp(_velocity.second + 0.5 * acceleration.second * dt,
                                                 -logic::constants::PLAYER_VERTICAL_TERMINAL_VELOCITY,
                                                 logic::constants::PLAYER_VERTICAL_TERMINAL_VELOCITY)};

    _left_collision = false;
    _right_collision = false;
    _down_collision = false;
    _up_collision = false;

    double added_y_distance = velo.second * dt;
    double added_x_distance = velo.first * dt;

    if (collisionPlayerWithEntity(goal, added_x_distance, added_y_distance)) {
        return true;
    }

    for (int i = 0; i < walls.size(); i++) {
        for (int k = 0; k < walls[0].size(); k++) {
            if ((walls[i][k]->getTexture() != "none")) {
                collisionPlayerWithEntity(walls[i][k], added_x_distance, added_y_distance);
            }
        }
    }

    if (firstKey) {
        setPosition(_position.first + added_x_distance, _position.second + added_y_distance);
        _velocity.first += acceleration.first * dt;
        _velocity.second += acceleration.second * dt;
    }

    return false;
}
