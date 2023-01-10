//
// Created by student on 5/12/22.
//

#include "Subject.h"
#include "Observer.h"

void logic::Subject::Attach(logic::EVENT e, std::shared_ptr<logic::Observer> o) { _observers[e].push_back(o); }

void logic::Subject::Notify(logic::EVENT e) {
    for (auto& observer : _observers[e]) {
        observer->update(e, this);
    }
}