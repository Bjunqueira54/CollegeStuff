#include "Sailboat.h"

/*Sailboat::Sailboat() {}

Sailboat::Sailboat(const Sailboat& orig) {}*/

Sailboat::Sailboat(Player* o, int id, int x, int y): Ship(o, id, x, y, 2, 20, 200, 40) {}

const string Sailboat::getShipInfo() const
{
    ostringstream os;

    os << getID() << " 1 " << getCoord() << " " << getDestCoord() << " " << getCrew() << " " << getMaxcrew() << " ";
    os << getWater() << " " << getMaxwater() << " " << getFish() << " " << getCargo() << " " << getMaxload();
    
    return os.str();
}

Sailboat::~Sailboat() {}