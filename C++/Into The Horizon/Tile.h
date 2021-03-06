#ifndef TILE_H
#define TILE_H

#include "headers.h"

class Tile
{
    const int y, x;
    
public:
    
    Tile() = delete;
    Tile(int yy, int xx);
    
    const string getCoord() const;
    
    virtual ~Tile();
};

#endif