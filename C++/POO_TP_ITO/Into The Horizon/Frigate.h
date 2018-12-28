#ifndef FRIGATE_H
#define FRIGATE_H

#include "Ship.h"

class Frigate: public Ship
{
    
public:
    
    /*Frigate();
    Frigate(const Frigate& orig);*/
    Frigate(Player* o, int id, int x, int y);
    
    const int getType() const { return 4; }
    
    virtual ~Frigate();
};

#endif