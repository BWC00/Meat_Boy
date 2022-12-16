//
// Created by student on 1/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_WORLD_H
#define INC_2022_PROJECT_BWC00_WORLD_H

#include "AbstractFactory.h"
#include "INPUT.h"
#include <deque>

namespace logic {
    class World {
    public:
        explicit World(const std::shared_ptr<logic::AbstractFactory>&, const std::string&);
        void update(INPUT);
    private:
        std::shared_ptr<logic::Player> _player;
        std::vector<std::vector<std::shared_ptr<logic::Wall> > > _walls;
        std::shared_ptr<logic::Goal> _goal;
        std::shared_ptr<logic::AbstractFactory> _factory;
        std::shared_ptr<logic::Score> _score;
        bool collisionWithPlayer(const std::shared_ptr<logic::EntityModel>& object) const;
        void reset();
        void tick();
        void exit();
    };
}


#endif //INC_2022_PROJECT_BWC00_WORLD_H
