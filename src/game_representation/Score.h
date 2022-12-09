//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_SCORE_H_VIEW
#define INC_2022_PROJECT_BWC00_SCORE_H_VIEW

#include "EntityView.h"
#include "../logic_library/Score.h"

namespace view {
    class Score final : public view::EntityView {
    public:
        explicit Score(std::shared_ptr<logic::Score>&);
        ~Score() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
        sf::Text _scoreText;
        std::weak_ptr<logic::Score> _subject;
    };
}


#endif //INC_2022_PROJECT_BWC00_SCORE_H_VIEW
