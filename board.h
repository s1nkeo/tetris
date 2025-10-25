#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
private:
    std::vector<std::vector<int>> grid;  // 2D вектор для поля
    int width;
    int height;

public:
    Board(int w = 10, int h = 20);      // Конструктор с размерами
    int getCell(int x, int y) const;     // Получить значение клетки
    void setCell(int x, int y, int value); // Установить значение клетки
    void clear();                        // Очистить поле
    bool isCollision(const std::vector<std::vector<int>>& piece, int posX, int posY) const; // Проверка столкновений
    void mergePiece(const std::vector<std::vector<int>>& piece, int posX, int posY, int value); // Объединить фигуру с полем
    int getWidth() const { return width; }
    int getHeight() const { return height; }
};

#endif