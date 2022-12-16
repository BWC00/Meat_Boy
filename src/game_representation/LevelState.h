//
// Created by student on 8/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_LEVELSTATE_H
#define INC_2022_PROJECT_BWC00_LEVELSTATE_H

#include "State.h"
#include "ConcreteFactory.h"
#include "../logic_library/World.h"

namespace view {
    class LevelState final : public State {
    public:
        void exitKey() override;
		void noInput() override;
		void rightKey() override;
		void leftKey() override;
		void upKey() override;
		void downKey() override;
		void spaceKey() override;
		void enterKey() override;
        void createWorld(const std::string&);
        void createFactory();
        ~LevelState() override = default;
        LevelState(const std::shared_ptr<StateManager>&, const std::string&);
    private:
        std::shared_ptr<logic::World> _world;
        std::shared_ptr<view::ConcreteFactory> _factory;
    };
}


#endif //INC_2022_PROJECT_BWC00_LEVELSTATE_H
