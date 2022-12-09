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
        Camera();
        ~Camera() override = default;
        //static std::pair<int, int> project(double x, double y);
        std::pair<int, int> project(const std::pair<double, double>& position);//, int windowWidth, int windowHeight);
        void shift_view(double amount);
        double getUpperBound() const;
        double getLowerBound() const;
        void Update(std::shared_ptr<logic::Player> player);
        bool getLost() const;
        void reset();
    private:
        std::pair<double, double> _windowBounds;
        bool _lost;
    };
}


#endif //INC_2022_PROJECT_BWC00_CAMERA_H
