#include <iostream>
#include <cstdlib>
#include "tetris.h"
using namespace std;

Game::Game() : y(0) {

}

void Game::init() {
    y = 0;
}

void Game::update() {
    y++;
    if (y > 10) y = 0;
}

void Game::render() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    for (int i = 0; i < y; ++i)
        cout << endl;

    cout << "⬛" << endl;
}