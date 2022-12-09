//
// Created by student on 8/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_LEVELSTATE_H
#define INC_2022_PROJECT_BWC00_LEVELSTATE_H

#include "State.h"
#include "../logic_library/World.h"
#include "ConcreteFactory.h"

namespace view {
    class LevelState : public State {
    public:
        void handleInput(logic::INPUT) override;
        ~LevelState() override = default;
    private:
        std::unique_ptr<logic::World> _world;
        std::shared_ptr<view::ConcreteFactory> _factory;
    };
}


#endif //INC_2022_PROJECT_BWC00_LEVELSTATE_H
