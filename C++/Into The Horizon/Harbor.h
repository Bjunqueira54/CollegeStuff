#ifndef HARBOR_H
#define HARBOR_H

#include "Tile.h"

class Harbor: public Tile
{
    const char id;
    bool friendly;
    
public:

    Harbor(char i, int yy, int xx);
    
    const bool isFriendly() const { return friendly; }
    const char getID() const { return id; }
    
    virtual ~Harbor();
};

#endif