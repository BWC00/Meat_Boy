//
// Created by student on 7/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_GIRLGOAL_H_VIEW
#define INC_2022_PROJECT_BWC00_GIRLGOAL_H_VIEW

#include "Goal.h"
#include "../logic_library/GirlGoal.h"

namespace view {
    class GirlGoal final : public view::Goal {
    public:
        ~GirlGoal() override = default;
        explicit GirlGoal(const std::shared_ptr<logic::GirlGoal>&);
    };
}

#endif //INC_2022_PROJECT_BWC00_GIRLGOAL_H_VIEW
