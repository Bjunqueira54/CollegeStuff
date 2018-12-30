#include "Special.h"

/*Special::Special() {}

Special::Special(const Special& orig) {}*/

Special::Special(Player* o, int id, int x, int y): Ship(o, id, x, y, 5, 500, 5000, 0) {}

const string Special::getShipInfo() const
{
    ostringstream os;

    os << getID() << " 5 " << getCoord() << " " << getDestCoord() << " " << getCrew() << " " << getMaxcrew() << " ";
    os << getWater() << " " << getMaxwater() << " " << getFish() << " " << getCargo() << " " << getMaxload();
    
    return os.str();
}

Special::~Special() {}