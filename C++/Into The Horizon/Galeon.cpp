#include "Galeon.h"

/*Galeon::Galeon() {}

Galeon::Galeon(const Galeon& orig) {}*/

Galeon::Galeon(Player* o, int id, int y, int x): Ship(o, id, y, x, true, 1, 40, 400, 70) {}

const string Galeon::getShipInfo() const
{
    ostringstream os;

    os << getID() << " 2 " << getCoord() << " " << getDestCoord() << " " << getCrew() << " " << getMaxcrew() << " ";
    os << getWater() << " " << getMaxwater() << " " << getFish() << " " << getCargo() << " " << getMaxload();
    
    return os.str();
}

Galeon::~Galeon() {}