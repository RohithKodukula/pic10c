//
//  bomb.cpp
//  minesweeper_zoeb_trial
//
//  Created by zoeb on 6/4/20.
//  Copyright © 2020 zoeb. All rights reserved.
//

#include "bomb.hpp"
bomb::bomb() {
    xcoord = 0;
    ycoord = 0;
}
bomb::bomb(int x, int y) {
    xcoord = x;
    ycoord = y;
}

int bomb::getXcoord() {
    return xcoord;
}

int bomb::getYcoord() {
    return ycoord;
}
