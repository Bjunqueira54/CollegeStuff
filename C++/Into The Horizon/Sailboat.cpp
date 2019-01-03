#include "Sailboat.h"

/*Sailboat::Sailboat() {}

Sailboat::Sailboat(const Sailboat& orig) {}*/

Sailboat::Sailboat(Player* o, int id, int y, int x, bool sih): Ship(o, id, y, x, sih, 2, 20, 200, 40) {}

const string Sailboat::getShipInfo() const
{
    ostringstream os;

    os << getID() << " 1 " << getCoord() << " " << getDestCoord() << " " << getCrew() << " " << getMaxcrew() << " ";
    os << getWater() << " " << getMaxwater() << " " << getFish() << " " << getCargo() << " " << getMaxload();
    
    return os.str();
}

Sailboat::~Sailboat() {}