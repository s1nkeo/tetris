#include "board.h"
#include <stdexcept>

Board::Board(int w, int h) : width(w), height(h) {
    grid.resize(height, std::vector<int>(width, 0)); // Инициализация нулями
}

int Board::getCell(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return grid[y][x];  // Осторожно: grid[y][x] - строка, затем столбец
    }
    return -1; // или бросить исключение
}

void Board::setCell(int x, int y, int value) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = value;
    }
}

void Board::clear() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = 0;
        }
    }
}

bool Board::isCollision(const std::vector<std::vector<int>>& piece, int posX, int posY) const {
    int pieceSize = piece.size();
    
    for (int y = 0; y < pieceSize; y++) {
        for (int x = 0; x < pieceSize; x++) {
            if (piece[y][x] != 0) { // Если часть фигуры есть
                int boardX = posX + x;
                int boardY = posY + y;
                
                // Проверка границ и столкновений
                if (boardX < 0 || boardX >= width || boardY >= height) {
                    return true;
                }
                if (boardY >= 0 && grid[boardY][boardX] != 0) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Board::mergePiece(const std::vector<std::vector<int>>& piece, int posX, int posY, int value) {
    int pieceSize = piece.size();
    
    for (int y = 0; y < pieceSize; y++) {
        for (int x = 0; x < pieceSize; x++) {
            if (piece[y][x] != 0) {
                int boardX = posX + x;
                int boardY = posY + y;
                
                if (boardX >= 0 && boardX < width && boardY >= 0 && boardY < height) {
                    grid[boardY][boardX] = value;
                }
            }
        }
    }
}