#include <iostream>
#include <windows.h>
#include "tetris.h"

int main() {
    Game game;
    game.init();

    while(true) {
        game.update();
        game.render();
        Sleep(500);  // Windows Sleep (milliseconds)
    }
    return 0;
}