//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_CONCRETEWALL_H
#define INC_2022_PROJECT_BWC00_CONCRETEWALL_H

#include "Wall.h"

namespace logic {
    class ConcreteWall final : public logic::Wall {
    public:
    ConcreteWall(double, double);
    ~ConcreteWall() override = default;
    void Update(logic::INPUT) override;
    };
}


#endif //INC_2022_PROJECT_BWC00_CONCRETEWALL_H
