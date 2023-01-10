//
// Created by Mohammed Shakleya on 09/01/2023.
//

#include "CONSTANTS.h"

namespace logic {
namespace constants {

// game window settings
extern const double INITIAL_WINDOW_LOWER_BOUND = 0.0;
extern const double INITIAL_WINDOW_UPPER_BOUND = 2.6666666666;
extern const double WINDOW_WIDTH = 2.0;
extern const double WINDOW_HEIGHT = 2.6666666666;

// renderwindow settings
extern const int RENDERWINDOW_WIDTH = 1200;
extern const int RENDERWINDOW_HEIGHT = 1600;

// Player settings
extern const double PLAYER_JUMP_HEIGHT = 0.6;
extern const double PLAYER_JUMP_TIME = 0.5;
extern const double PLAYER_HORIZONTAL_ACCELERATION = 4.0;
extern const double PLAYER_HORIZONTAL_TERMINAL_VELOCITY = 2.0;
extern const double PLAYER_VERTICAL_TERMINAL_VELOCITY = 10.0;

// MeatBoy settings
extern const double MEATBOY_HITBOX_WIDTH = 0.125;
extern const double MEATBOY_HITBOX_HEIGHT = 0.125;

// SimpleWall settings
extern const double SIMPLEWALL_HITBOX_WIDTH = 0.125;
extern const double SIMPLEWALL_HITBOX_HEIGHT = 0.125;

// GirlGoal settings
extern const double GIRLGOAL_HITBOX_WIDTH = 0.125;
extern const double GIRLGOAL_HITBOX_HEIGHT = 0.125;

extern const double AUTOVIEW_SHIFT_AMOUNT = 0.1;

extern const int FRAME_RATE = 60;
} // namespace constants
} // namespace logic