#include "Galeon.h"

/*Galeon::Galeon() {}

Galeon::Galeon(const Galeon& orig) {}*/

Galeon::Galeon(Player* o, int id, int x, int y): Ship(o, id, x, y, 1, 40, 400, 70) {}

const string Galeon::getShipInfo() const
{
    ostringstream os;

    os << getID() << " 2 " << getCoord() << " " << getDestCoord() << " " << getCrew() << " " << getMaxcrew() << " ";
    os << getWater() << " " << getMaxwater() << " " << getFish() << " " << getCargo() << " " << getMaxload();
    
    return os.str();
}

Galeon::~Galeon() {}