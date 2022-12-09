//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_GOAL_H
#define INC_2022_PROJECT_BWC00_GOAL_H


#include "EntityModel.h"

namespace logic {
    class Goal : public logic::EntityModel {
    public:
        Goal(double x, double y);
        ~Goal() override = default;
    };
}


#endif //INC_2022_PROJECT_BWC00_GOAL_H
