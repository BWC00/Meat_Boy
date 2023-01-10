//
// Created by student on 1/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_CONCRETEFACTORY_H
#define INC_2022_PROJECT_BWC00_CONCRETEFACTORY_H

#include "../logic_library/AbstractFactory.h"
#include <SFML/Graphics.hpp>

namespace view {
class ConcreteFactory : public logic::AbstractFactory {
public:
    std::shared_ptr<logic::Player> createPlayer(double x, double y, const std::string&, const std::string&) override;
    std::shared_ptr<logic::Wall> createWall(double, double, const std::string&, const std::string&) override;
    std::shared_ptr<logic::Goal> createGoal(double, double, const std::string&, const std::string&) override;

    template <typename SpecificEntityLogic, typename SpecificEntityView>
    std::shared_ptr<SpecificEntityLogic> createEntity(double x, double y, const std::string& textureName);

    ~ConcreteFactory() override = default;
};
} // namespace view

#endif // INC_2022_PROJECT_BWC00_CONCRETEFACTORY_H
