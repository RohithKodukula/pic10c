//
//  bomb.hpp
//  minesweeper_zoeb_trial
//
//  Created by zoeb on 6/4/20.
//  Copyright © 2020 zoeb. All rights reserved.
//

#ifndef bomb_hpp
#define bomb_hpp

#include <stdio.h>

class bomb {
public:
    bomb();
    bomb(int x, int y);
    int getXcoord();
    int getYcoord();
private:
    int xcoord;
    int ycoord;
};
#endif /* bomb_hpp */
