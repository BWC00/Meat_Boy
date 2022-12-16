//
// Created by student on 8/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_STATE_H
#define INC_2022_PROJECT_BWC00_STATE_H

#include <memory>

namespace view {
	class StateManager;
    class State {
    public:
        virtual void exitKey() = 0;
		virtual void noInput() = 0;
		virtual void rightKey() = 0;
		virtual void leftKey() = 0;
		virtual void upKey() = 0;
		virtual void downKey() = 0;
		virtual void spaceKey() = 0;
		virtual void enterKey() = 0;

		explicit State(const std::shared_ptr<StateManager>&);
        State()=default;
        virtual ~State()=default;
    protected:
    	std::shared_ptr<StateManager> _stateManager = nullptr;
    };
}


#endif //INC_2022_PROJECT_BWC00_STATE_H
