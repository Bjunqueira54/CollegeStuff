#ifndef WARRIOR_H
#define WARRIOR_H

#include "includes.h"
#include "Class.h"

class Warrior: public Class
{
    
public:
    Warrior();
    Warrior(const Warrior& orig);
    virtual ~Warrior();

private:

};

#endif