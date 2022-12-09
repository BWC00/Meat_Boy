//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_PLAYER_H_VIEW
#define INC_2022_PROJECT_BWC00_PLAYER_H_VIEW

#include "EntityView.h"
#include "../logic_library/Player.h"

namespace view {
    class Player : public view::EntityView {
    public:
        explicit Player(const std::shared_ptr<logic::Player>&);
        ~Player() override = default;
    };
}


#endif //INC_2022_PROJECT_BWC00_PLAYER_H_VIEW
