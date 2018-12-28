#ifndef GALEON_H
#define GALEON_H

#include "Ship.h"

class Galeon: public Ship
{
    
public:
    
    /*Galeon();
    Galeon(const Galeon& orig);*/
    Galeon(Player* o, int id, int x, int y);
    
    virtual ~Galeon();
};

#endif