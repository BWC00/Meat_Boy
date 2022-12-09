//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_WALL_H_VIEW
#define INC_2022_PROJECT_BWC00_WALL_H_VIEW

#include "EntityView.h"
#include "../logic_library/Wall.h"

namespace view {
    class Wall : public view::EntityView {
    public:
        explicit Wall(const std::shared_ptr<logic::Wall>&);
        ~Wall() override = default;
    };
}

#endif //INC_2022_PROJECT_BWC00_WALL_H_VIEW
