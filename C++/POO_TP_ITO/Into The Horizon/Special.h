#ifndef SPECIAL_H
#define SPECIAL_H

#include "Ship.h"

//ALL HAIL THE SHIP OF THE LINE!

class Special: public Ship
{
    
public:
    /*Special();
    Special(const Special& orig);*/
    Special(Player* o, int id, int x, int y);
    
    const int getType() const { return 5; }
	const string getShipInfo() const;
    
    virtual ~Special();
};

#endif