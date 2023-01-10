//
// Created by student on 8/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_STATE_H
#define INC_2022_PROJECT_BWC00_STATE_H

#include "../logic_library/EVENT.h"
#include <memory>

namespace view {
class StateManager;
class State {
public:
    virtual void handleInput(logic::EVENT, bool) = 0;
    void setStateManager(const std::shared_ptr<StateManager>&);

    State() = default;
    virtual ~State() = default;

protected:
    std::weak_ptr<StateManager> _stateManager;
};
} // namespace view

#endif // INC_2022_PROJECT_BWC00_STATE_H
