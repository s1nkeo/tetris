#ifndef RENDER_H
#define RENDER_H

#include "board.h"

class Render {
public:
    static void drawBoard(const Board& board);
    static void clearScreen();
    static void drawCell(int value);  // для отрисовки отдельной клетки
};

#endif