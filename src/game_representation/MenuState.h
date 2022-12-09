//
// Created by student on 8/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_MENUSTATE_H
#define INC_2022_PROJECT_BWC00_MENUSTATE_H

#include "State.h"

namespace view {
    class MenuState : public State {
    public:
        MenuState();
        ~MenuState() override = default;
        void handleInput(logic::INPUT) override;
    };
}


#endif //INC_2022_PROJECT_BWC00_MENUSTATE_H
