#ifndef SAILBOAT_H
#define SAILBOAT_H

#include "Ship.h"

class Sailboat: public Ship
{
    
public:
    
    /*Sailboat();
    Sailboat(const Sailboat& orig);*/
    Sailboat(Player* o, int id, int x, int y);
    
    virtual ~Sailboat();
};

#endif