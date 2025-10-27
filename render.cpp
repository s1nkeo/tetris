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

void Render::drawCell(int value) {
    if (value == 0) {
        cout << ". ";  // Empty cell
    } else {
        // Different symbols or colors for different piece types
        // For now, using # for all pieces
        cout << "# ";
        
        // Future: Add colors here based on value
        // if (value == 1) cout << "I ";
        // else if (value == 2) cout << "O ";
        // etc.
    }
}

void Render::drawBoard(const Board& board) {
    clearScreen();
    
    cout << "=== TETRIS ===" << endl;
    cout << "==============" << endl;
    
    int width = board.getWidth();
    int height = board.getHeight();
    
    // Top border
    cout << "+";
    for (int x = 0; x < width; x++) {
        cout << "--";
    }
    cout << "+" << endl;
    
    // Game field
    for (int y = 0; y < height; y++) {
        cout << "|";  // Left border
        
        for (int x = 0; x < width; x++) {
            int cell = board.getCell(x, y);
            drawCell(cell);
        }
        
        cout << "|" << endl;  // Right border
    }
    
    // Bottom border
    cout << "+";
    for (int x = 0; x < width; x++) {
        cout << "--";
    }
    cout << "+" << endl;
    
    // Controls
    cout << "Controls: A-left, D-right, S-down, SPACE-rotate, Q-quit" << endl;
}