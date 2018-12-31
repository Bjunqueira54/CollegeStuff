#ifndef OCEAN_H
#define OCEAN_H

#include "Tile.h"

class Ocean: public Tile
{
    int tleft, fish;

public:
    
    Ocean(int yy, int xx);
    
    
    
    virtual ~Ocean();
};

#endif