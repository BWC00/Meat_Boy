//
// Created by Mohammed Shakleya on 09/01/2023.
//

#ifndef INC_2022_PROJECT_BWC00_CONSTANTS_H
#define INC_2022_PROJECT_BWC00_CONSTANTS_H

#include <string>

namespace logic {
namespace constants {

// game window settings
extern const double INITIAL_WINDOW_LOWER_BOUND;
extern const double INITIAL_WINDOW_UPPER_BOUND;
extern const double WINDOW_WIDTH;
extern const double WINDOW_HEIGHT;

// renderwindow settings
extern const int RENDERWINDOW_WIDTH;
extern const int RENDERWINDOW_HEIGHT;

// Player settings
extern const double PLAYER_JUMP_HEIGHT;
extern const double PLAYER_JUMP_TIME;
extern const double PLAYER_HORIZONTAL_ACCELERATION;
extern const double PLAYER_HORIZONTAL_TERMINAL_VELOCITY;
extern const double PLAYER_VERTICAL_TERMINAL_VELOCITY;

// MeatBoy settings
extern const double MEATBOY_HITBOX_WIDTH;
extern const double MEATBOY_HITBOX_HEIGHT;

// SimpleWall settings
extern const double SIMPLEWALL_HITBOX_WIDTH;
extern const double SIMPLEWALL_HITBOX_HEIGHT;

// GirlGoal settings
extern const double GIRLGOAL_HITBOX_WIDTH;
extern const double GIRLGOAL_HITBOX_HEIGHT;

extern const double AUTOVIEW_SHIFT_AMOUNT;

extern const int FRAME_RATE;
} // namespace constants
} // namespace logic

#endif // INC_2022_PROJECT_BWC00_CONSTANTS_H
