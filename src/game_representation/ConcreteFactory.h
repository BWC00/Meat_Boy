//
// Created by student on 1/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_CONCRETEFACTORY_H
#define INC_2022_PROJECT_BWC00_CONCRETEFACTORY_H


#include "../logic_library/AbstractFactory.h"
#include <SFML/Graphics.hpp>


namespace view {
class ConcreteFactory: public logic::AbstractFactory {
    public:
        explicit ConcreteFactory();
        ~ConcreteFactory() override = default;
        std::shared_ptr<logic::Player> createPlayer(double x, double y) override;
        std::shared_ptr<logic::Wall> createWall(double, double) override;
        std::shared_ptr<logic::Goal> createGoal(double, double) override;
        std::shared_ptr<logic::Score> createScore() override;
    private:
        std::shared_ptr<logic::Score> _score = nullptr;
    };
}


#endif //INC_2022_PROJECT_BWC00_CONCRETEFACTORY_H
