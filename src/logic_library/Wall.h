//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_WALL_H
#define INC_2022_PROJECT_BWC00_WALL_H

#include "EntityModel.h"

namespace logic {
class Wall : public logic::EntityModel {
public:
    Wall(double, double, const std::string&);
    ~Wall() override = default;
};
} // namespace logic

#endif // INC_2022_PROJECT_BWC00_WALL_H
