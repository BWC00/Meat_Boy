//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_PLAYER_H
#define INC_2022_PROJECT_BWC00_PLAYER_H

#include "EVENT.h"
#include "EntityModel.h"
#include "Goal.h"
#include "Wall.h"

namespace logic {

class Player : public logic::EntityModel {
public:
    Player(double, double, const std::string&);
    ~Player() override = default;
    bool update(logic::EVENT, const std::vector<std::vector<std::shared_ptr<Wall>>>&, const std::shared_ptr<Goal>&,
                bool);
    bool collisionPlayerWithEntity(const std::shared_ptr<logic::EntityModel>&, double&, double&);
    void reset();

private:
    std::pair<double, double> _velocity;
    double _jumpHeight;
    double _jumpTime;

    bool _jumped;
    bool _spaceable;
    bool _up_collision;
    bool _down_collision;
    bool _right_collision;
    bool _left_collision;
};
} // namespace logic

#endif // INC_2022_PROJECT_BWC00_PLAYER_H
