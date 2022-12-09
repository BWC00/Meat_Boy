//
// Created by student on 5/12/22.
//

#include "Score.h"
#include <cmath>

logic::Score::Score(const std::shared_ptr<logic::Camera>& view) : _score(0) {
    _view = view;
}

int logic::Score::getScore() const {
    return _score;
}

void logic::Score::Update(logic::EVENT e, logic::Subject* changedSubject) {
    if (changedSubject == _view.lock().get()) {
        //if (!_view.lock()->getLost()) {
        if (e == logic::EVENT::MOVE) {
            _score = static_cast<int>(std::round(5*(((double)(_view.lock()->getLowerBound()-2))/0.10))); //15
        }
        //}
    }
}