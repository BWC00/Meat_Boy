//
// Created by student on 8/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_MENUSTATE_H
#define INC_2022_PROJECT_BWC00_MENUSTATE_H

#include "Level.h"
#include "State.h"
#include "StateManager.h"
#include <vector>

namespace view {
class MenuState : public State {
public:
    void handleInput(logic::EVENT, bool) override;

    ~MenuState() override = default;
    MenuState();

private:
    void draw();

    std::string prevKey;
    std::unique_ptr<sf::Sprite> _background;
};
} // namespace view

#endif // INC_2022_PROJECT_BWC00_MENUSTATE_H
