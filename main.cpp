#include <iostream>
#include "piece.h"

using namespace std;

// Helper function to display a shape
void printShape(const vector<vector<int>>& shape) {
    for (const auto& row : shape) {
        for (int cell : row) {
            cout << (cell ? "# " : ". "); // # for filled, . for empty
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Test all 7 piece types
    Piece pieces[] = {
        Piece(PieceType::I),
        Piece(PieceType::O),
        Piece(PieceType::T),
        Piece(PieceType::L),
        Piece(PieceType::J),
        Piece(PieceType::S),
        Piece(PieceType::Z)
    };
    
    const char* names[] = {"I", "O", "T", "L", "J", "S", "Z"};
    
    cout << "All Tetromino Pieces:" << endl;
    cout << "=====================" << endl;
    
    for (int i = 0; i < 7; i++) {
        cout << "Piece: " << names[i] << endl;
        printShape(pieces[i].getShape());
    }
    
    return 0;
}