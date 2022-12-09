//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_SUBJECT_H
#define INC_2022_PROJECT_BWC00_SUBJECT_H

#include "EVENT.h"
#include <memory>
#include <vector>
#include <map>

namespace logic {
    class Observer;

    class Subject {
    public:
        virtual ~Subject();
        void Attach(logic::EVENT, std::shared_ptr<logic::Observer>);
        void Notify(logic::EVENT);
    private:
        std::map<logic::EVENT,std::vector<std::shared_ptr<logic::Observer>>> _observers;
    };
}


#endif //INC_2022_PROJECT_BWC00_SUBJECT_H
