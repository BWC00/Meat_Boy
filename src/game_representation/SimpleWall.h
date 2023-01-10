//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_CONCRETEWALL_H_VIEW
#define INC_2022_PROJECT_BWC00_CONCRETEWALL_H_VIEW

#include "../logic_library/SimpleWall.h"
#include "Wall.h"

namespace view {
class SimpleWall final : public view::Wall {
public:
    explicit SimpleWall(const std::shared_ptr<logic::SimpleWall>&, const std::string&);
    ~SimpleWall() override = default;
};
} // namespace view

#endif // INC_2022_PROJECT_BWC00_CONCRETEWALL_H_VIEW