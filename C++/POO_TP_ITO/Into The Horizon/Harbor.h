#ifndef HARBOR_H
#define HARBOR_H

#include "Tile.h"

class Harbor: public Tile
{
    const int x, y;
public:
    
    Harbor();
    Harbor(const Harbor& orig);
    
    const string getCoord() const;
    
    virtual ~Harbor();
};

#endif