//
// Created by student on 1/12/22.
//

#include "ConcreteFactory.h"
#include "GirlGoal.h"
#include "MeatBoy.h"
#include "SimpleWall.h"

std::shared_ptr<logic::Player> view::ConcreteFactory::createPlayer(double x, double y, const std::string& typeName,
                                                                   const std::string& textureName) {
    if (typeName == "MeatBoy") {
        return createEntity<logic::MeatBoy, view::MeatBoy>(x, y, textureName);
    }
    return {};
}

std::shared_ptr<logic::Goal> view::ConcreteFactory::createGoal(double x, double y, const std::string& typeName,
                                                               const std::string& textureName) {
    if (typeName == "GirlGoal") {
        return createEntity<logic::GirlGoal, view::GirlGoal>(x, y, textureName);
    }
    return {};
}

std::shared_ptr<logic::Wall> view::ConcreteFactory::createWall(double x, double y, const std::string& typeName,
                                                               const std::string& textureName) {
    if (typeName == "none" || typeName == "SimpleWall") {
        return createEntity<logic::SimpleWall, view::SimpleWall>(x, y, textureName);
    }
    return {};
}

template <typename SpecificEntityLogic, typename SpecificEntityView>
std::shared_ptr<SpecificEntityLogic> view::ConcreteFactory::createEntity(double x, double y,
                                                                         const std::string& textureName) {
    std::shared_ptr<SpecificEntityLogic> entityModel = std::make_shared<SpecificEntityLogic>(x, y, textureName);
    std::shared_ptr<SpecificEntityView> entityView = std::make_shared<SpecificEntityView>(entityModel, textureName);
    entityModel->Attach(logic::EVENT::TICK, entityView);
    return entityModel;
}