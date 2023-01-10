//
// Created by student on 8/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_LEVELSTATE_H
#define INC_2022_PROJECT_BWC00_LEVELSTATE_H

#include "../logic_library/World.h"
#include "ConcreteFactory.h"
#include "State.h"

namespace view {
class LevelState final : public State {
public:
    void handleInput(logic::EVENT, bool) override;
    void createWorld(const std::string&);

    ~LevelState() override = default;
    LevelState();

private:
    void checkIfWon(bool);

    std::unique_ptr<logic::World> _world;
    const std::string _currentLevelName;
    const std::string _nextLevelName;
    std::unique_ptr<sf::Sprite> _background;
};
} // namespace view

#endif // INC_2022_PROJECT_BWC00_LEVELSTATE_H
