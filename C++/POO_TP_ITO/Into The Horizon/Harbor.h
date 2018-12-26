#ifndef HARBOR_H
#define HARBOR_H

#include "Tile.h"

class Harbor: public Tile
{
    const int x, y;
    const char id;
    bool friendly;
    
public:
    
    /*Harbor();
    Harbor(const Harbor& orig);*/
    Harbor(char i, int yy, int xx);
    
    const string getCoord() const;
    
    virtual ~Harbor();
};

#endif