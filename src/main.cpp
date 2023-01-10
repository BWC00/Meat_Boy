#include <iostream>
#include "game_representation/Game.h"
#include <memory>

//werk aan de parameters x en y (positie van entities) te supportere in de logic
int main()
{
    try {
        view::Game game;
        game.run();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (...) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
