#include "Schooner.h"

/*Schooner::Schooner() {}

Schooner::Schooner(const Schooner& orig) {}*/

Schooner::Schooner(Player* o, int id, int y, int x): Ship(o, id, y, x, true, 1, 10, 100, 20) {}

const string Schooner::getShipInfo() const
{
    ostringstream os;

    os << getID() << " 3 " << getCoord() << " " << getDestCoord() << " " << getCrew() << " " << getMaxcrew() << " ";
    os << getWater() << " " << getMaxwater() << " " << getFish() << " " << getCargo() << " " << getMaxload();
    
    return os.str();
}

Schooner::~Schooner() {}