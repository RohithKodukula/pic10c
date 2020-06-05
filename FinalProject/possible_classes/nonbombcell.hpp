//
//  nonbombcell.hpp
//  minesweeper_zoeb_trial
//
//  Created by zoeb on 6/5/20.
//  Copyright © 2020 zoeb. All rights reserved.
//

#ifndef nonbombcell_hpp
#define nonbombcell_hpp

#include <stdio.h>
class nonbombcell {
public:
    nonbombcell();
    nonbombcell(int x, int y);
    int getXcoord();
    int getYcoord();
    void incrementNumberOfAdjacentBombs();
private:
    int xcoord;
    int ycoord;
    int numberOfAdjacentBombs;
};
#endif /* nonbombcell_hpp */
