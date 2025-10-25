#include <iostream>
#include <windows.h>
#include "tetris.h"

using namespace std;

int main() {
    Game game;
    game.init();

    // Тестовая отрисовка
    for (int i = 0; i < 5; i++) {
        game.render();
        cout << "Frame: " << i + 1 << endl;
        Sleep(1000);  // Windows Sleep (milliseconds)
    }
    
    return 0;
}