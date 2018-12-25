#ifndef SPECIAL_H
#define SPECIAL_H

#include "Ship.h"

//ALL HAIL THE SHIP OF THE LINE!

class Special: public Ship
{
    
    
public:
    Special();
    Special(const Special& orig);
    Special(int x, int y);
    
    
    
    virtual ~Special();
};

#endif