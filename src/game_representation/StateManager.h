//
// Created by student on 8/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_STATEMANAGER_H
#define INC_2022_PROJECT_BWC00_STATEMANAGER_H

#include "ConcreteFactory.h"
#include "State.h"

namespace view {
class State;
class StateManager : public std::enable_shared_from_this<StateManager> {
public:
    StateManager();
    void handleInput(logic::EVENT, bool);
    void changeState(std::unique_ptr<view::State>);
    ~StateManager() = default;

private:
    std::unique_ptr<view::State> _state;
};
} // namespace view

#endif // INC_2022_PROJECT_BWC00_STATEMANAGER_H
