//
// Created by student on 7/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_MEATBOY_H_VIEW
#define INC_2022_PROJECT_BWC00_MEATBOY_H_VIEW

#include "Player.h"
#include "../logic_library/MeatBoy.h"

namespace view {
    class MeatBoy final : public view::Player {
    public:
        ~MeatBoy() override = default;
        explicit MeatBoy(const std::shared_ptr<logic::MeatBoy>&);
    };
}

#endif //INC_2022_PROJECT_BWC00_MEATBOY_H_VIEW
