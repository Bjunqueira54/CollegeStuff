#ifndef OCEAN_H
#define OCEAN_H

#include "Tile.h"

class Ocean: public Tile
{
    int y, x, tleft, fish;

public:
    
    Ocean();
    Ocean(const Ocean& orig);
    Ocean(int yy, int xx);
    
    
    
    virtual ~Ocean();
};

#endif