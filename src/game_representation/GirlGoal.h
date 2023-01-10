//
// Created by student on 7/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_GIRLGOAL_H_VIEW
#define INC_2022_PROJECT_BWC00_GIRLGOAL_H_VIEW

#include "../logic_library/GirlGoal.h"
#include "Goal.h"

namespace view {
class GirlGoal final : public view::Goal {
public:
    GirlGoal(const std::shared_ptr<logic::GirlGoal>&, const std::string&);
    ~GirlGoal() override = default;
};
} // namespace view

#endif // INC_2022_PROJECT_BWC00_GIRLGOAL_H_VIEW
