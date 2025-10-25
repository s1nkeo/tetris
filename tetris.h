#ifndef TETRIS_H
#define TETRIS_H

class Game {
    private:
        int y; // vertical coordinate y

    public:
        Game();
        void init();
        void update();
        void render();
};

#endif