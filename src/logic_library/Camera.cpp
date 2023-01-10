//
// Created by student on 5/12/22.
//

#include "Camera.h"
#include "CONSTANTS.h"
#include "Player.h"
#include <cmath>

logic::Camera::Camera() {
    _windowBounds.first = logic::constants::INITIAL_WINDOW_LOWER_BOUND;
    _windowBounds.second = logic::constants::INITIAL_WINDOW_UPPER_BOUND;
}

logic::Camera& logic::Camera::getCamera() {
    static Camera instance;
    return instance;
}

void logic::Camera::reset() {
    getCamera()._windowBounds.first = logic::constants::INITIAL_WINDOW_LOWER_BOUND;
    getCamera()._windowBounds.second = logic::constants::INITIAL_WINDOW_UPPER_BOUND;
}

void logic::Camera::shiftView(double amount) { getCamera().shift_view(amount); }

double logic::Camera::getLowerBound() { return getCamera()._windowBounds.first; }

double logic::Camera::getUpperBound() { return getCamera()._windowBounds.second; }

void logic::Camera::shift_view(double amount) {
    _windowBounds.first += amount;
    _windowBounds.second += amount;
}

std::pair<int, int> logic::Camera::project(const std::pair<double, double>& position) {
    return std::make_pair(
        static_cast<int>(std::round((position.first + 1.0) *
                                    (logic::constants::RENDERWINDOW_WIDTH / logic::constants::WINDOW_WIDTH))),
        static_cast<int>(std::round((_windowBounds.second - position.second) *
                                    (logic::constants::RENDERWINDOW_HEIGHT / logic::constants::WINDOW_HEIGHT))));
}

void logic::Camera::update(const std::shared_ptr<logic::Player>& player) {
    double amount = player->getPosition().second - (_windowBounds.first + (4.0 / 5) * logic::constants::WINDOW_HEIGHT);
    if (amount > 0) {
        shift_view(amount);
    }
}