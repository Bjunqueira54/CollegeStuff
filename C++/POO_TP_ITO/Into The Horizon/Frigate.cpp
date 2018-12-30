#include "Frigate.h"

/*Frigate::Frigate() {}

Frigate::Frigate(const Frigate& orig) {}*/

Frigate::Frigate(Player* o, int id, int x, int y): Ship(o, id, x, y, 2, 50, 500, 0) {
}

const string Frigate::getShipInfo() const
{
    ostringstream os;

    os << getID() << " 4 " << getCoord() << " " << getDestCoord() << " " << getCrew() << " " << getMaxcrew() << " ";
    os << getWater() << " " << getMaxwater() << " " << getFish() << " " << getCargo() << " " << getMaxload();
    
    return os.str();
}

Frigate::~Frigate() {}