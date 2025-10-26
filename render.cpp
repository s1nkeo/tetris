#include "render.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void Render::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Render::drawBoard(const Board& board) {
    clearScreen();
    
    cout << "=== TETRIS ===" << endl;
    cout << "==============" << endl;
    
    int width = board.getWidth();
    int height = board.getHeight();
    
    // Upper board
    cout << "+";
    for (int x = 0; x < width; x++) {
        cout << "--";
    }
    cout << "+" << endl;
    
    // Playground
    for (int y = 0; y < height; y++) {
        cout << "|";  // left
        
        for (int x = 0; x < width; x++) {
            int cell = board.getCell(x, y);
            if (cell == 0) {
                cout << ". ";  // space
            } else {
                cout << "# ";   
            }
        }
        
        cout << "|" << endl;  // right
    }
    
    // Low board
    cout << "+";
    for (int x = 0; x < width; x++) {
        cout << "--";
    }
    cout << "+" << endl;
    
    cout << "Controls: [A] left, [D] right, [S] down, [SPACE] rotate, [Q] quit" << endl;
}