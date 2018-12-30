#include "Ship.h"
#include "Player.h"

Ship::Ship(Player* o, int i, int yy, int xx, int mm, int mc, int mw, int ml): id(i), y(yy), x(xx), maxmoves(mm), maxcrew(mc), maxwater(mw), maxload(ml)
{
    owner = o;
    moves = maxmoves;
    crew = maxcrew;
    water = maxwater;
    fish = cargo = 0;
    destx = x;
    desty = y;
}

const string Ship::getCoord() const
{
    ostringstream os;
    
    os << y << " " << x;
    
    return os.str();
}

const string Ship::getDestCoord() const
{
    ostringstream os;
    
    os << desty << " " << destx;
    
    return os.str();
}

int Ship::setDestination(int dy, int dx, bool idh)
{
    desty = dy;
    destx = dx;
    DestHarbor = idh;
    
    if(Auto)
        Auto = false;
}

void Ship::move(int newy, int newx)
{
    x = newx;
    y = newy;
    
    if(x == destx && y == desty)
    {
        if(DestHarbor == true)
        {
            inHarbor = true;
        }
        Stopped = true;
    }
}

Ship::~Ship() {}