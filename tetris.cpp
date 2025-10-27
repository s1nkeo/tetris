#include "tetris.h"
#include "render.h"
#include <iostream>
#include <chrono>

using namespace std;

Game::Game() : board(10, 20), gameOver(false), score(0) {
    // Initialize random number generator with current time
    rng.seed(chrono::system_clock::now().time_since_epoch().count());
}

void Game::init() {
    board.clear();
    gameOver = false;
    score = 0;
    
    // Spawn first piece
    spawnPiece();
}

PieceType Game::getRandomPieceType() {
    // Create uniform distribution for 7 piece types
    uniform_int_distribution<int> dist(0, 6);
    
    int randomValue = dist(rng);
    
    // Convert integer to PieceType
    switch (randomValue) {
        case 0: return PieceType::I;
        case 1: return PieceType::O;
        case 2: return PieceType::T;
        case 3: return PieceType::L;
        case 4: return PieceType::J;
        case 5: return PieceType::S;
        case 6: return PieceType::Z;
        default: return PieceType::T; // Fallback
    }
}

void Game::spawnPiece() {
    // Get random piece type
    PieceType newType = getRandomPieceType();
    
    // Calculate spawn position (centered at top)
    int spawnX = board.getWidth() / 2 - 1; // Center horizontally
    int spawnY = 0; // Top of the board
    
    // Create new piece
    currentPiece = Piece(newType, spawnX, spawnY);
    
    // If the spawn position is invalid, game over
    if (!isValidPosition(currentPiece)) {
        gameOver = true;
        cout << "Game Over! Cannot spawn new piece." << endl;
    }
}

bool Game::isValidPosition(const Piece& piece) const {
    const vector<vector<int>>& shape = piece.getShape();
    int pieceX = piece.getX();
    int pieceY = piece.getY();
    int pieceSize = shape.size();
    
    // Check each cell of the piece
    for (int y = 0; y < pieceSize; y++) {
        for (int x = 0; x < pieceSize; x++) {
            if (shape[y][x] != 0) { // If this is part of the piece
                int boardX = pieceX + x;
                int boardY = pieceY + y;
                
                // Check if out of bounds
                if (boardX < 0 || boardX >= board.getWidth() || boardY >= board.getHeight()) {
                    return false;
                }
                
                // Check if collides with existing blocks (only check if within board vertically)
                if (boardY >= 0 && board.getCell(boardX, boardY) != 0) {
                    return false;
                }
            }
        }
    }
    
    return true;
}

void Game::mergePieceToBoard() {
    const vector<vector<int>>& shape = currentPiece.getShape();
    int pieceX = currentPiece.getX();
    int pieceY = currentPiece.getY();
    int pieceSize = shape.size();
    
    // Use piece type as value for coloring (1-7)
    int cellValue = static_cast<int>(currentPiece.getType()) + 1;
    
    for (int y = 0; y < pieceSize; y++) {
        for (int x = 0; x < pieceSize; x++) {
            if (shape[y][x] != 0) {
                int boardX = pieceX + x;
                int boardY = pieceY + y;
                
                // Only set if within board bounds
                if (boardX >= 0 && boardX < board.getWidth() && 
                    boardY >= 0 && boardY < board.getHeight()) {
                    board.setCell(boardX, boardY, cellValue);
                }
            }
        }
    }
}

void Game::update() {
    if (gameOver) return;
    
    // Try to move current piece down
    Piece testPiece = currentPiece;
    testPiece.move(0, 1); // Move down
    
    if (isValidPosition(testPiece)) {
        // Valid move - update position
        currentPiece = testPiece;
    } else {
        // Cannot move down - merge to board and spawn new piece
        mergePieceToBoard();
        spawnPiece();
    }
}

void Game::handleInput(char key) {
    if (gameOver) return;
    
    Piece testPiece = currentPiece;
    
    switch (key) {
        case 'a': // Move left
        case 'A':
            testPiece.move(-1, 0);
            break;
            
        case 'd': // Move right
        case 'D':
            testPiece.move(1, 0);
            break;
            
        case 's': // Move down
        case 'S':
            testPiece.move(0, 1);
            break;
            
        case ' ': // Rotate (spacebar)
            testPiece.rotate();
            break;
            
        default:
            return; // Unknown key
    }
    
    // Apply move if valid
    if (isValidPosition(testPiece)) {
        currentPiece = testPiece;
    }
}

void Game::render() {
    // Create a temporary board for rendering (current board + current piece)
    Board renderBoard = board;
    
    // Add current piece to render board
    const vector<vector<int>>& shape = currentPiece.getShape();
    int pieceX = currentPiece.getX();
    int pieceY = currentPiece.getY();
    int pieceSize = shape.size();
    
    // Use piece type as value for coloring
    int cellValue = static_cast<int>(currentPiece.getType()) + 1;
    
    for (int y = 0; y < pieceSize; y++) {
        for (int x = 0; x < pieceSize; x++) {
            if (shape[y][x] != 0) {
                int boardX = pieceX + x;
                int boardY = pieceY + y;
                
                if (boardX >= 0 && boardX < renderBoard.getWidth() && 
                    boardY >= 0 && boardY < renderBoard.getHeight()) {
                    renderBoard.setCell(boardX, boardY, cellValue);
                }
            }
        }
    }
    
    // Render the board with current piece
    Render::drawBoard(renderBoard);
    
    // Display game info
    cout << "Score: " << score << endl;
    cout << "Current Piece: ";
    switch (currentPiece.getType()) {
        case PieceType::I: cout << "I"; break;
        case PieceType::O: cout << "O"; break;
        case PieceType::T: cout << "T"; break;
        case PieceType::L: cout << "L"; break;
        case PieceType::J: cout << "J"; break;
        case PieceType::S: cout << "S"; break;
        case PieceType::Z: cout << "Z"; break;
    }
    cout << endl;
    
    if (gameOver) {
        cout << "=== GAME OVER ===" << endl;
    }
}