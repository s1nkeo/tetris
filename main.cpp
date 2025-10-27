#include <iostream>
#include <windows.h>
#include <conio.h>
#include "tetris.h"

using namespace std;

int main() {
    Game game;
    game.init();

    cout << "Tetris - Piece Spawning Test" << endl;
    cout << "Press any key to start..." << endl;
    getch();

    // Game loop
    while (!game.isGameOver()) {
        game.render();
        
        // Check for input
        if (_kbhit()) {
            char key = _getch();
            if (key == 'q' || key == 'Q') break;
            game.handleInput(key);
        }
        
        game.update();
        Sleep(500);
    }

    game.render(); // Final render
    cout << "Game ended. Press any key to exit." << endl;
    getch();
    
    return 0;
}