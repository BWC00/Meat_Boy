//
// Created by student on 8/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_STATEMANAGER_H
#define INC_2022_PROJECT_BWC00_STATEMANAGER_H

#include "ConcreteFactory.h"

namespace view {
	class State;
    class StateManager {
    public:
        StateManager();
        void exitKey();
		void noInput();
		void rightKey();
		void leftKey();
		void upKey();
		void downKey();
		void spaceKey();
		void enterKey();
		void changeState(const State&);
    private:
        State& _state;
    };
}


#endif //INC_2022_PROJECT_BWC00_STATEMANAGER_H
