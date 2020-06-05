//
//  minesweeper.hpp
//  minesweeper_zoeb_trial
//
//  Created by zoeb on 6/4/20.
//  Copyright © 2020 zoeb. All rights reserved.
//

#ifndef minesweeper_hpp
#define minesweeper_hpp

#include <stdio.h>
class minesweeper {
public:
    minesweeper();
    minesweeper(int numberOfBombs);
    void printBoard() const;
    void initializeBoard();
private:
    int bombs;
    int board [8][8]{};
};
#endif /* minesweeper_hpp */
