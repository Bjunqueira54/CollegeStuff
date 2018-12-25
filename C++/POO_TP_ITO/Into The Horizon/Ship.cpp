#include "Ship.h"
#include "Player.h"

Ship::Ship() {}

Ship::Ship(const Ship& orig) {}

Ship::Ship(Player &o, int xx, int yy, int mm, int mc, int mw, int ml): x(xx), y(yy), maxmoves(mm), maxcrew(mc), maxwater(mw), maxload(ml)
{
    owner = &o;
    moves = maxmoves;
    crew = maxcrew;
    water = maxwater;
    fish = load = 0;
}

Ship::~Ship() {}