//
// Created by student on 1/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_ABSTRACTFACTORY_H
#define INC_2022_PROJECT_BWC00_ABSTRACTFACTORY_H

#include "Goal.h"
#include "Player.h"

namespace logic {
class AbstractFactory {
public:
    virtual std::shared_ptr<logic::Player> createPlayer(double, double, const std::string&, const std::string&) = 0;
    virtual std::shared_ptr<logic::Wall> createWall(double, double, const std::string&, const std::string&) = 0;
    virtual std::shared_ptr<logic::Goal> createGoal(double, double, const std::string&, const std::string&) = 0;
    virtual ~AbstractFactory() = default;
};
} // namespace logic

#endif // INC_2022_PROJECT_BWC00_ABSTRACTFACTORY_H
