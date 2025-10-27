#ifndef TETRIS_H
#define TETRIS_H

#include "board.h"
#include "piece.h"
#include <random>

class Game {
private:
    Board board;
    Piece currentPiece;
    Piece nextPiece;
    bool gameOver;
    int score;
    std::mt19937 rng; // Random number generator
    
public:
    Game();
    void init();
    void update();
    void render();
    void handleInput(char key);
    
    // New methods for piece management
    void spawnPiece();
    PieceType getRandomPieceType();
    bool isValidPosition(const Piece& piece) const;
    void mergePieceToBoard();
    
    // Getters
    bool isGameOver() const { return gameOver; }
    int getScore() const { return score; }
};

#endif