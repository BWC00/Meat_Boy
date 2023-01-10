//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_SIMPLEWALL_H
#define INC_2022_PROJECT_BWC00_SIMPLEWALL_H

#include "Wall.h"

namespace logic {
class SimpleWall final : public logic::Wall {
public:
    SimpleWall(double, double, const std::string&);
    ~SimpleWall() override = default;
};
} // namespace logic

#endif // INC_2022_PROJECT_BWC00_SIMPLEWALL_H
