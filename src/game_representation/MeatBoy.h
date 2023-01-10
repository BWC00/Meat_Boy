//
// Created by student on 7/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_MEATBOY_H_VIEW
#define INC_2022_PROJECT_BWC00_MEATBOY_H_VIEW

#include "../logic_library/MeatBoy.h"
#include "Player.h"

namespace view {
class MeatBoy final : public view::Player {
public:
    MeatBoy(const std::shared_ptr<logic::MeatBoy>&, const std::string&);
    ~MeatBoy() override = default;
};
} // namespace view

#endif // INC_2022_PROJECT_BWC00_MEATBOY_H_VIEW
