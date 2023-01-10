//
// Created by student on 8/12/22.
//

#include "State.h"

#include "StateManager.h"
#include <utility>

void view::State::setStateManager(const std::shared_ptr<StateManager>& p) { _stateManager = p; }