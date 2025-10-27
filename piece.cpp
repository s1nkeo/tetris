#include "piece.h"
#include <vector>

using namespace std;

// Constructor - initializes piece with specific type and position
Piece::Piece(PieceType t, int startX, int startY) 
    : type(t), x(startX), y(startY) {
    color = getColorByType(type);
    initializeShape();
}

// Initialize the shape matrix based on piece type
void Piece::initializeShape() {
    shape = getShapeByType(type);
}

// Returns the shape matrix for each piece type
// 1 = filled cell, 0 = empty cell
vector<vector<int>> Piece::getShapeByType(PieceType type) {
    switch (type) {
        case PieceType::I: // I-piece (long bar)
            return {
                {0, 0, 0, 0},
                {1, 1, 1, 1},  // 4 cells in a row
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            };
            
        case PieceType::O: // O-piece (square)
            return {
                {1, 1},
                {1, 1}  // 2x2 block
            };
            
        case PieceType::T: // T-piece
            return {
                {0, 1, 0},
                {1, 1, 1},  // T shape
                {0, 0, 0}
            };
            
        case PieceType::L: // L-piece
            return {
                {0, 0, 1},
                {1, 1, 1},  // L shape
                {0, 0, 0}
            };
            
        case PieceType::J: // J-piece (mirror L)
            return {
                {1, 0, 0},
                {1, 1, 1},  // J shape
                {0, 0, 0}
            };
            
        case PieceType::S: // S-piece
            return {
                {0, 1, 1},
                {1, 1, 0},  // S shape
                {0, 0, 0}
            };
            
        case PieceType::Z: // Z-piece (mirror S)
            return {
                {1, 1, 0},
                {0, 1, 1},  // Z shape
                {0, 0, 0}
            };
            
        default: // Fallback to O-piece
            return {
                {1, 1},
                {1, 1}
            };
    }
}

// Returns color for each piece type (matching classic Tetris colors)
PieceColor Piece::getColorByType(PieceType type) {
    switch (type) {
        case PieceType::I: return PieceColor::CYAN;    // I - Cyan
        case PieceType::O: return PieceColor::YELLOW;  // O - Yellow
        case PieceType::T: return PieceColor::PURPLE;  // T - Purple
        case PieceType::L: return PieceColor::ORANGE;  // L - Orange
        case PieceType::J: return PieceColor::BLUE;    // J - Blue
        case PieceType::S: return PieceColor::GREEN;   // S - Green
        case PieceType::Z: return PieceColor::RED;     // Z - Red
        default: return PieceColor::CYAN;
    }
}

// Rotate the piece 90 degrees clockwise
void Piece::rotate() {
    shape = getRotatedShape();
}

// Calculate and return rotated shape without modifying current piece
vector<vector<int>> Piece::getRotatedShape() const {
    int size = shape.size();
    vector<vector<int>> rotated(size, vector<int>(size, 0));
    
    // Matrix rotation: 90 degrees clockwise
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            rotated[j][size - 1 - i] = shape[i][j];
        }
    }
    
    return rotated;
}