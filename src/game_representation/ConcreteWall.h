//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_CONCRETEWALL_H_VIEW
#define INC_2022_PROJECT_BWC00_CONCRETEWALL_H_VIEW

#include "Wall.h"
#include "../logic_library/ConcreteWall.h"

namespace view {
    class ConcreteWall final : public view::Wall {
    public:
        explicit ConcreteWall(const std::shared_ptr<logic::ConcreteWall>&);
        ~ConcreteWall() override = default;
    };
}


#endif //INC_2022_PROJECT_BWC00_CONCRETEWALL_H_VIEW