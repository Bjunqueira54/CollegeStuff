#include "Ship.h"
#include "Player.h"

Ship::Ship(Player* o, int i, int xx, int yy, int mm, int mc, int mw, int ml): id(i), x(xx), y(yy), maxmoves(mm), maxcrew(mc), maxwater(mw), maxload(ml)
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

Ship::~Ship() {}