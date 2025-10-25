#ifndef TETRIS_H
#define TETRIS_H
#include "board.h"

class Game {
    private:
        Board board;
        int y; // vertical coordinate y

    public:
        Game();
        void init();
        void update();
        void render();
};

#endif