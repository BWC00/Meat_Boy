//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_WALL_H
#define INC_2022_PROJECT_BWC00_WALL_H

#include "EntityModel.h"

namespace logic {
    class Wall : public logic::EntityModel {
    public:
        Wall(double, double);
        ~Wall() override = default;
    };
}


#endif //INC_2022_PROJECT_BWC00_WALL_H
