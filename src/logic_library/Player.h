//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_PLAYER_H
#define INC_2022_PROJECT_BWC00_PLAYER_H

#include "EntityModel.h"
#include "Wall.h"


namespace logic {

    enum class PLAYER {
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    class Player : public logic::EntityModel {
    public:
        Player(double, double);
        ~Player() override = default;
        void setJumpHeight(double);
        void setJumpDuration(double);
        PLAYER getDirection() const;
        void Update(logic::INPUT) override;
        const std::pair<double, double>& getPrevPosition() const;
        void Jumped();
        PLAYER getFacing() const;
        void setLowerBound(double a);
        void setUpperBound(double a);
        void died();
        std::weak_ptr<logic::Wall> _platformUnderPlayer;
    private:
        PLAYER _direction;
        PLAYER _facing;
        bool _jumped;
        std::pair<double, double> _velocity;
        std::pair<double, double> _prevPosition;
        double _jumpHeight;
        double _jumpTime;
        bool _dead;
        double _lowerBound;
        double _upperBound;
    };
}


#endif //INC_2022_PROJECT_BWC00_PLAYER_H
