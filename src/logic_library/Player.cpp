//
// Created by student on 5/12/22.
//

#include "Player.h"
#include "Stopwatch.h"
#include <cmath>
#include <algorithm>

logic::Player::Player(double x, double y) : logic::EntityModel(x,y) {
    _jumpHeight = 1.2;
    _jumpTime = 0.6;
    _velocity.first = 0;
    _velocity.second = 0;
    _jumped = true;
    _direction = logic::PLAYER::UP;
    _facing = logic::PLAYER::RIGHT;
    _hitBox.first = 0.35;
    _hitBox.second = 0.35;
    _dead = false;
}

void logic::Player::setJumpHeight(double h) {
    _jumpHeight = h;
}

void logic::Player::died() {
    _dead = true;
}

void logic::Player::setJumpDuration(double x) {
    _jumpTime = x;
}

logic::PLAYER logic::Player::getDirection() const {
    return _direction;
}

void logic::Player::Jumped() {
    _jumped = true;
}

const std::pair<double, double>& logic::Player::getPrevPosition() const {
    return _prevPosition;
}

logic::PLAYER logic::Player::getFacing() const {
    return _facing;
}

void logic::Player::setLowerBound(double a) {
    _lowerBound = a;
}

void logic::Player::setUpperBound(double a) {
    _upperBound = a;
}



void logic::Player::Update(logic::INPUT input) {
/*    if (_jumped) {
        _velocity.second = _initial_velocity;
        _jumped = false;
    }*/
    double initial_velocity = 2*_jumpHeight/_jumpTime;
    double g = -2*_jumpHeight/(_jumpTime*_jumpTime);
    double dt = Stopwatch::getElapsed().count()/1000;

    if (_jumped) {
        _velocity.second = initial_velocity;
        _direction = logic::PLAYER::UP;
        _jumped = false;
    }
    if (_velocity.second < 0) {
        _direction = logic::PLAYER::DOWN;
    }
    std::pair<double, double> acceleration;
    acceleration.second = g;
    acceleration.first = 0;
    if (input == logic::INPUT::RIGHT) {
        acceleration.first = 7.0;
        _facing = logic::PLAYER::RIGHT;
    } else if (input == logic::INPUT::LEFT) {
        acceleration.first = -7.0;
        _facing = logic::PLAYER::LEFT;
    } else {
        _velocity.first *= pow(0.95, dt/0.016);
    }
    //std::cout << "original x: " << _position.first << ", original y: " << _position.second << std::endl;
    //std::cout << "modified x: " << _position.first+_velocity.first*0.015 + 0.5*acceleration.first*0.015*0.015 << ", modified y: " << _position.second + _velocity.second*0.015 + 0.5*acceleration.second*0.015*0.015;
    std::pair<double, double> velo = {std::clamp(_velocity.first+0.5*acceleration.first*dt, -3.0, 3.0), _velocity.second+0.5*acceleration.second*dt};//std::clamp(_velocity.second+0.5*acceleration.second*dt, -10.0, 100.0)};
    _prevPosition = _position;

    double added_y_distance = velo.second*dt;
    double DISTANCE_FROM_ORIGIN_TO_LEFTMOST_FOOT = 0.25*_hitBox.first;
    double DISTANCE_FROM_ORIGIN_TO_RIGHTMOST_FOOT = (0.25+0.48)*_hitBox.first;
    //beweeg voor prio op de bonus ipv op de platform als je door de platform gaat
    if (not(_dead) && (_platformUnderPlayer.lock()) && (_direction == logic::PLAYER::DOWN) && (std::abs(added_y_distance) > std::abs(_position.second-_hitBox.second-_platformUnderPlayer.lock()->getPosition().second)) && (_position.first+DISTANCE_FROM_ORIGIN_TO_RIGHTMOST_FOOT > _platformUnderPlayer.lock()->getPosition().first) && (_position.first+DISTANCE_FROM_ORIGIN_TO_LEFTMOST_FOOT < _platformUnderPlayer.lock()->getPosition().first+_platformUnderPlayer.lock()->getHitbox().first)) {
        _jumpHeight = 1.2;
        _jumpTime = 0.6;
        setPosition(_position.first+velo.first*dt,_hitBox.second+_platformUnderPlayer.lock()->getPosition().second);
        _jumped = true;
        //Notify(logic::EVENT::JUMP);
    } else {
        setPosition(_position.first+velo.first*dt, _position.second + velo.second*dt);
    }
    _velocity.first += acceleration.first*dt;
    _velocity.second += acceleration.second*dt;
    Notify(logic::EVENT::MOVE);
/*    setPosition(_position.first+_velocity.first*0.015 + 0.5*acceleration.first*0.015*0.015, _position.second + _velocity.second*0.015 + 0.5*acceleration.second*0.015*0.015);
    _velocity.first += acceleration.first*0.015;
    _velocity.second += acceleration.second*0.015;*/
}
