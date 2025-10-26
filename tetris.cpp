#include "tetris.h"
#include "render.h"

Game::Game() : board(10, 20) {
    
}

void Game::init() {
    board.clear();
    
    // Test
    board.setCell(3, 18, 1);
    board.setCell(4, 18, 1);
    board.setCell(5, 18, 1);
    board.setCell(5, 17, 1);
}

void Game::render() {
    Render::drawBoard(board);
}

void Game::update() {
    
}