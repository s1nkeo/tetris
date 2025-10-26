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
        cout << "· ";  // пустая клетка
    } else {
        cout << "■ ";  // занятая клетка
    }
}

// Альтернативная версия в render.cpp (если нужны простые символы)
void Render::drawBoard(const Board& board) {
    clearScreen();
    
    cout << "=== TETRIS ===" << endl;
    cout << "==============" << endl;
    
    int width = board.getWidth();
    int height = board.getHeight();
    
    // Верхняя граница
    cout << "+";
    for (int x = 0; x < width; x++) {
        cout << "--";
    }
    cout << "+" << endl;
    
    // Игровое поле
    for (int y = 0; y < height; y++) {
        cout << "|";  // левая граница
        
        for (int x = 0; x < width; x++) {
            int cell = board.getCell(x, y);
            if (cell == 0) {
                cout << ". ";  // пустая клетка
            } else {
                cout << "# ";  // занятая клетка
            }
        }
        
        cout << "|" << endl;  // правая граница
    }
    
    // Нижняя граница
    cout << "+";
    for (int x = 0; x < width; x++) {
        cout << "--";
    }
    cout << "+" << endl;
    
    cout << "Controls: [A] left, [D] right, [S] down, [SPACE] rotate, [Q] quit" << endl;
}