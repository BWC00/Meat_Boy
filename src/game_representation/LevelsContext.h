//
// Created by Mohammed Shakleya on 16/12/2022.
//

#ifndef INC_2022_PROJECT_BWC00_LEVELSCONTEXT_H
#define INC_2022_PROJECT_BWC00_LEVELSCONTEXT_H

#include "Level.h"
#include <vector>

namespace view {
class LevelsContext {
public:
    // getters
    static LevelsContext& getInstance();
    static const std::string& getCurrentLevelName();
    static sf::Texture& getCurrentLevelBackgroundTexture();

    static void goPrevLevel();
    static void goNextLevel();
    static void drawMenu();

    LevelsContext(const LevelsContext&) = delete;

private:
    LevelsContext();
    void _goPrevLevel();
    void _goNextLevel();
    void _drawMenu();

    int _currentLevel;
    std::vector<std::unique_ptr<view::Level>> _levels;
    const int MAX_LEVELS_ON_SCREEN = 10;
};
} // namespace view

#endif // INC_2022_PROJECT_BWC00_LEVELSCONTEXT_H