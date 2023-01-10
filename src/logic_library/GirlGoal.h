
//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_GIRLGOAL_H
#define INC_2022_PROJECT_BWC00_GIRLGOAL_H

#include "Goal.h"

namespace logic {
class GirlGoal : public logic::Goal {
public:
    GirlGoal(double, double, const std::string&);
    ~GirlGoal() override = default;
};
} // namespace logic

#endif // INC_2022_PROJECT_BWC00_GIRLGOAL_H
