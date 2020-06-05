//
//  main.cpp
//  minesweeper_zoeb_trial
//
//  Created by zoeb on 6/4/20.
//  Copyright © 2020 zoeb. All rights reserved.
//

#include <iostream>
#include "bomb.hpp"
#include "minesweeper.hpp"
#include "nonbombcell.hpp"
//in board, 10 = bomb

int main () {
    minesweeper game(8);
    game.initializeBoard();
    game.printBoard();
}
