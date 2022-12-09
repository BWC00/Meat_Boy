//
// Created by student on 8/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_STATE_H
#define INC_2022_PROJECT_BWC00_STATE_H

#include "../logic_library/INPUT.h"

namespace view {
    class State {
    public:
        virtual void handleInput(logic::INPUT) = 0;
        virtual ~State() = default;
    };
}


#endif //INC_2022_PROJECT_BWC00_STATE_H
