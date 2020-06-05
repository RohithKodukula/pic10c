//
//  minesweeper.cpp
//  minesweeper_zoeb_trial
//
//  Created by zoeb on 6/4/20.
//  Copyright © 2020 zoeb. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include "minesweeper.hpp"
#include "bomb.hpp"

minesweeper::minesweeper() {
    bombs = 0;
}

minesweeper::minesweeper(int numberOfBombs) {
    bombs = numberOfBombs;
}

void minesweeper::printBoard() const {
    std::cout << std::setw(4);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << board[i][j] << std::setw(4);
        }
        std::cout << std::endl << std::endl;
    }
}


void minesweeper::initializeBoard() {
    srand(time(NULL));
    int min = 0;
    int max = 7;
    for (int i = 0; i < bombs; i++) {
        int bombx = min + (rand() % static_cast<int>(max - min + 1));
        int bomby = min + (rand() % static_cast<int>(max - min + 1));
        bomb* b = new bomb(bombx, bomby);
        if (board [b->getXcoord()][b->getYcoord()] != 10) {
            board [b->getXcoord()][b->getYcoord()] = 10;
        }
        for (int i = 0; i < 8; i++) {
            
        }
    }
}




