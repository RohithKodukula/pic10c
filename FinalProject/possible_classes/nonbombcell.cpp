//
//  nonbombcell.cpp
//  minesweeper_zoeb_trial
//
//  Created by zoeb on 6/5/20.
//  Copyright © 2020 zoeb. All rights reserved.
//

#include "nonbombcell.hpp"

nonbombcell::nonbombcell() {
    xcoord = 0;
    ycoord = 0;
    numberOfAdjacentBombs = 0;
}

nonbombcell::nonbombcell(int x, int y) {
    xcoord = x;
    ycoord = y;
}

int nonbombcell::getXcoord() {
    return xcoord;
}

int nonbombcell::getYcoord() {
    return ycoord;
}

void nonbombcell::incrementNumberOfAdjacentBombs() {
    numberOfAdjacentBombs++;
}
