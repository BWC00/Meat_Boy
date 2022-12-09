//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_GOAL_H_VIEW
#define INC_2022_PROJECT_BWC00_GOAL_H_VIEW

#include "EntityView.h"
#include "../logic_library/Goal.h"

namespace view {
    class Goal : public view::EntityView {
    public:
        explicit Goal(const std::shared_ptr<logic::Goal>&);
        ~Goal() override = default;
    };
}

#endif //INC_2022_PROJECT_BWC00_GOAL_H_VIEW
