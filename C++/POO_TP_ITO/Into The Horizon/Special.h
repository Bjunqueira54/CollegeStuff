#ifndef SPECIAL_H
#define SPECIAL_H

#include "Ship.h"

class Special: public Ship
{
public:
    Special();
    Special(const Special& orig);
    virtual ~Special();
};

#endif