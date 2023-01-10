//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_OBSERVER_H
#define INC_2022_PROJECT_BWC00_OBSERVER_H

#include "EVENT.h"

namespace logic {
class Subject;
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(logic::EVENT, logic::Subject*) = 0;
};
} // namespace logic

#endif // INC_2022_PROJECT_BWC00_OBSERVER_H
