//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_SCORE_H
#define INC_2022_PROJECT_BWC00_SCORE_H


#include "Observer.h"
#include "Subject.h"
#include "Camera.h"

namespace logic {
    class Subject;
    class Score : public logic::Observer, public logic::Subject {
    public:
        Score();
        ~Score() override = default;
        void Update(logic::EVENT, logic::Subject*) override;
        int getScore() const;
    private:
        int _score;
    };
}


#endif //INC_2022_PROJECT_BWC00_SCORE_H
