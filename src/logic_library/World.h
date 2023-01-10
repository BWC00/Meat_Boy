//
// Created by student on 1/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_WORLD_H
#define INC_2022_PROJECT_BWC00_WORLD_H

#include "AbstractFactory.h"
#include <deque>

namespace logic {
class World {
public:
    bool update(logic::EVENT, bool);

    explicit World(std::unique_ptr<logic::AbstractFactory>, const std::string&);

private:
    void createLevel(const std::string&);
    void reset();
    void tick();

    // entities
    std::shared_ptr<logic::Player> _player;
    std::vector<std::vector<std::shared_ptr<logic::Wall>>> _walls;
    std::shared_ptr<logic::Goal> _goal;
    std::unique_ptr<logic::AbstractFactory> _factory;

    // for automatic scrolling
    bool autoView;
};
} // namespace logic

#endif // INC_2022_PROJECT_BWC00_WORLD_H
