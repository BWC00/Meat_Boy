//
// Created by student on 8/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_STATEMANAGER_H
#define INC_2022_PROJECT_BWC00_STATEMANAGER_H

#include "../logic_library/INPUT.h"
#include "ConcreteFactory.h"
#include "../logic_library/World.h"
#include "State.h"

namespace view {
    class StateManager {
    public:
        StateManager();
        void handleInput(logic::INPUT);
    private:
        void Update();
        std::shared_ptr<view::State> _state;
    };
}


#endif //INC_2022_PROJECT_BWC00_STATEMANAGER_H
