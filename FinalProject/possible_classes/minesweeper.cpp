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
#include "nonbombcell.hpp"

minesweeper::minesweeper() {
    bombs = 0;
}

minesweeper::minesweeper(int numberOfBombs) {
    bombs = numberOfBombs;
}

void minesweeper::printBoard() const {
    std::cout << std::setw(4);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << board[i][j] << std::setw(4);
        }
        std::cout << std::endl << std::endl;
    }
}


void minesweeper::initializeBoard() {
    srand(time(NULL));
    int min = 0;
    int max = 9;
    int validBombPlacements = 0;
    while (validBombPlacements < bombs) {
        int bombx = min + (rand() % static_cast<int>(max - min + 1));
        int bomby = min + (rand() % static_cast<int>(max - min + 1));
        bomb* b = new bomb(bombx, bomby);
        if (board [b->getXcoord()][b->getYcoord()] != 10) {
            board [b->getXcoord()][b->getYcoord()] = 10;
            validBombPlacements++;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board [i][j] != 10) {
                if (board[i - 1][j + 1] == 10) {
                    board[i - 1][j + 1] += 1;
                }
                /*nonbombcell* n = new nonbombcell(i, j);
                if (board [n->getXcoord() - 1][n->getYcoord() + 1] == 10) {
                    board [n->getXcoord() - 1][n->getYcoord() + 1]+=1;
                }
                if (board [n->getXcoord() - 1][n->getYcoord()] == 10) {
                    board [n->getXcoord() - 1][n->getYcoord()]+=1;
                }
                if (board [n->getXcoord() - 1][n->getYcoord() - 1] == 10) {
                    board [n->getXcoord() - 1][n->getYcoord() - 1]+=1;
                }
                if (board [n->getXcoord()][n->getYcoord() + 1] == 10) {
                    board [n->getXcoord()][n->getYcoord() + 1]+=1;
                }
                if (board [n->getXcoord()][n->getYcoord() - 1] == 10) {
                    board [n->getXcoord()][n->getYcoord() - 1]+=1;
                }
                if (board [n->getXcoord() + 1][n->getYcoord() + 1] == 10) {
                    board [n->getXcoord() + 1][n->getYcoord() + 1]+=1;
                }
                if (board [n->getXcoord() + 1][n->getYcoord()] == 10) {
                    board [n->getXcoord() + 1][n->getYcoord()]+=1;
                }
                if (board [n->getXcoord() + 1][n->getYcoord() - 1] == 10) {
                    board [n->getXcoord() + 1][n->getYcoord() - 1]+=1;
                }*/
            }
        }
    }
}





