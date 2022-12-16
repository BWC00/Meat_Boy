 //
// Created by student on 1/12/22.
//

#include "ConcreteFactory.h"
#include "Score.h"
#include "MeatBoy.h"
#include "GirlGoal.h"
#include "ConcreteWall.h"
#include "../logic_library/Camera.h"

 view::ConcreteFactory::ConcreteFactory() {
     _score = std::make_shared<logic::Score>();
     std::shared_ptr<view::Score> view_score = std::make_shared<view::Score>(_score);
     _score->Attach(logic::EVENT::MOVE, view_score);
     //std::shared_ptr<view::Score> score_view = std::make_shared<view::Score>(_score);
     //_score->Attach(logic::EVENT::TICK, score_view);
     //score_view->setView(_view);
     //score_view->setWindow(_window);
     logic::Camera::getCamera().Attach(logic::EVENT::MOVE, _score); //score moet geupdatted worden wnr de camera moves
 }

 std::shared_ptr<logic::Player> view::ConcreteFactory::createPlayer(double x, double y) {
     std::shared_ptr<logic::MeatBoy> player_model = std::make_shared<logic::MeatBoy>(x,y);
     std::shared_ptr<view::MeatBoy> player_view = std::make_shared<view::MeatBoy>(player_model);
     player_model->Attach(logic::EVENT::MOVE, player_view);
     return player_model;
 }

 std::shared_ptr<logic::Goal> view::ConcreteFactory::createGoal(double x, double y) {
    std::shared_ptr<logic::GirlGoal> goal_model = std::make_shared<logic::GirlGoal>(x,y);
    std::shared_ptr<view::Goal> goal_view = std::make_shared<view::Goal>(goal_model);
    goal_model->Attach(logic::EVENT::COLLISION, goal_view); //wanneer er collision is met de goal moet de menu weergegeve worden
                                                            // er moet ook pas getekend worden wanneer de steentjes in beeld zijn
    return goal_model;
}

std::shared_ptr<logic::Wall> view::ConcreteFactory::createWall(double x, double y) {
    std::shared_ptr<logic::ConcreteWall> wall_model = std::make_shared<logic::ConcreteWall>(x,y);
    std::shared_ptr<view::ConcreteWall> wall_view = std::make_shared<view::ConcreteWall>(wall_model); //texture meegeven aan view

    //wall'en drawen wanneer ze in beeld zijn en dan terug niet drawen

    return wall_model;
}

 std::shared_ptr<logic::Score> view::ConcreteFactory::createScore() {
     return _score;
 }