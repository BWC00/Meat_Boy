//
// Created by student on 8/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_MENUSTATE_H
#define INC_2022_PROJECT_BWC00_MENUSTATE_H

#include "State.h"
#include "StateManager.h"
#include <vector>
#include "Level.h"

namespace view {
    class MenuState : public State {
    public:
    	void exitKey() override;
		void noInput() override;
		void rightKey() override;
		void leftKey() override;
		void upKey() override;
		void downKey() override;
		void spaceKey() override;
		void enterKey() override;
        MenuState(const MenuState&) = delete;
    	static MenuState& getInstance(const std::shared_ptr<StateManager>&);
        ~MenuState() override = default;
    private:
        MenuState();
        void draw();
        int _currentLevel;
    	std::vector<view::Level> _levels;
        const int MAX_LEVELS_ON_SCREEN = 10;
        std::string prevKey;
        sf::Sprite _background;
    };
}


#endif //INC_2022_PROJECT_BWC00_MENUSTATE_H
