#ifndef PIECE_H
#define PIECE_H

#include <vector>

// Tetromino piece types
enum class PieceType {
    I, O, T, L, J, S, Z  // All 7 standard tetromino shapes
};

// Colors for different pieces (optional - for future rendering)
enum class PieceColor {
    CYAN, YELLOW, PURPLE, ORANGE, BLUE, GREEN, RED
};

class Piece {
private:
    PieceType type;
    PieceColor color;
    std::vector<std::vector<int>> shape; // 2D matrix representing the piece
    int x, y; // Position on the game board
    
public:
    // Constructor with default values
    Piece(PieceType type = PieceType::I, int startX = 0, int startY = 0);
    
    // Getters
    PieceType getType() const { return type; }
    PieceColor getColor() const { return color; }
    const std::vector<std::vector<int>>& getShape() const { return shape; }
    int getX() const { return x; }
    int getY() const { return y; }
    
    // Position setters
    void setPosition(int newX, int newY) { x = newX; y = newY; }
    void move(int dx, int dy) { x += dx; y += dy; }
    
    // Rotation methods
    void rotate();
    std::vector<std::vector<int>> getRotatedShape() const;
    
    // Static methods to get piece data
    static std::vector<std::vector<int>> getShapeByType(PieceType type);
    static PieceColor getColorByType(PieceType type);
    
private:
    void initializeShape();
};

#endif