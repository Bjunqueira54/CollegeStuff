#ifndef HARBOR_H
#define HARBOR_H

#include "Tile.h"

class Harbor: public Tile
{
    
public:
    
    Harbor();
    Harbor(const Harbor& orig);
    virtual ~Harbor();
};

#endif