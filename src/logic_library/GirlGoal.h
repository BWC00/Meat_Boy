
//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_GIRLGOAL_H
#define INC_2022_PROJECT_BWC00_GIRLGOAL_H

#include "Goal.h"

namespace logic {
    class GirlGoal : public logic::Goal {
    public:
        GirlGoal(double, double);
        ~GirlGoal() override = default;
        void Update(logic::INPUT) override;
    };
}


#endif //INC_2022_PROJECT_BWC00_GIRLGOAL_H
