//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_MEATBOY_H
#define INC_2022_PROJECT_BWC00_MEATBOY_H

#include "Player.h"

namespace logic {
class MeatBoy final : public logic::Player {
public:
    MeatBoy(double x, double y, const std::string&);
    ~MeatBoy() override = default;
};
} // namespace logic

#endif // INC_2022_PROJECT_BWC00_MEATBOY_H
