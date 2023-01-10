//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_CAMERA_H
#define INC_2022_PROJECT_BWC00_CAMERA_H

#include "Subject.h"

namespace logic {
class Player;
class Camera : public logic::Subject {
public:
    // getters
    static double getUpperBound();
    static double getLowerBound();

    std::pair<int, int> project(const std::pair<double, double>& position);
    void update(const std::shared_ptr<logic::Player>& player);
    static void shiftView(double amount);
    void shift_view(double amount);
    static void reset();

    Camera(const Camera&) = delete;
    static Camera& getCamera();
    ~Camera() override = default;

private:
    Camera();
    std::pair<double, double> _windowBounds;
};
} // namespace logic

#endif // INC_2022_PROJECT_BWC00_CAMERA_H
