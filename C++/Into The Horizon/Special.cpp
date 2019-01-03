#include "Special.h"

/*Special::Special() {}

Special::Special(const Special& orig) {}*/

Special::Special(Player* o, int id, int y, int x): Ship(o, id, y, x, true, 5, 500, 5000, 0) {}

const string Special::getShipInfo() const
{
    ostringstream os;

    os << getID() << " 5 " << getCoord() << " " << getDestCoord() << " " << getCrew() << " " << getMaxcrew() << " ";
    os << getWater() << " " << getMaxwater() << " " << getFish() << " " << getCargo() << " " << getMaxload();
    
    return os.str();
}

Special::~Special() {}