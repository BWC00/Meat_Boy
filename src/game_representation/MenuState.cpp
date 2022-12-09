//
// Created by student on 8/12/22.
//

#include <dirent.h>
#include "MenuState.h"
#include <iostream>

view::MenuState::MenuState() {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("../Data/Levels")) != nullptr) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != nullptr) {
            printf ("%s\n", ent->d_name);
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        //return EXIT_FAILURE;
    }
}

void view::MenuState::handleInput(logic::INPUT) {

}