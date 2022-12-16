//
// Created by student on 1/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_ABSTRACTFACTORY_H
#define INC_2022_PROJECT_BWC00_ABSTRACTFACTORY_H

#include "Player.h"
#include "Score.h"
#include "Goal.h"


namespace logic {
    class AbstractFactory {
    public:
        virtual std::shared_ptr<logic::Player> createPlayer(double, double) = 0;
        virtual std::shared_ptr<logic::Wall> createWall(double, double) = 0;
        virtual std::shared_ptr<logic::Goal> createGoal(double, double) = 0;
        virtual std::shared_ptr<logic::Score> createScore() = 0;
        virtual ~AbstractFactory() = default;
    };
}


#endif //INC_2022_PROJECT_BWC00_ABSTRACTFACTORY_H
