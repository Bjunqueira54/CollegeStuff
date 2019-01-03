#include "Ship.h"
#include "Player.h"

Ship::Ship(Player* o, int i, int yy, int xx, int mm, int mc, int mw, int ml): id(i), y(yy), x(xx), moves(mm), maxcrew(mc), maxwater(mw), maxload(ml)
{
    owner = o;
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
    specMoving = true;
    
    if(Auto)
        Auto = false;
    
    return 0;
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
        else
        {
            inHarbor = false;
        }
        
        Stopped = true;
        specMoving = false;
    }
}

int Ship::Stop()
{
    destx = x;
    desty = y;
}

int Ship::addCargo(int c)
{
    int leftovers = 0, auxmax;
    
    auxmax = maxload - fish;

    cargo += c;
    
    if(cargo > auxmax)
    {
        leftovers = cargo - auxmax;
        cargo = auxmax;
    }
    else if(cargo < 0)
    {
        //abs() wasn't working for some reason, so I gotta improvise and adapt.
        leftovers = (cargo * 2) + cargo;
        cargo = 0;
    }
    
    return leftovers;
}

int Ship::addFish(int f)
{
    int leftovers = 0, auxmax;
    
    auxmax = maxload - cargo;
    
    fish += f;
    
    if(fish > auxmax)
    {
        leftovers = fish - auxmax;
        fish = auxmax;
    }
    else if(fish < 0)
    {
        leftovers = (fish * 2) - fish;
        fish = 0;
    }
    
    return leftovers;
}

int Ship::addCrew(int c)
{
    int leftovers = 0;
    
    crew += c;
    
    if(crew > maxcrew)
    {
        leftovers = crew - maxcrew;
        crew = maxcrew;
    }
    else if(crew < 0)
    {
        leftovers = (crew * 2) - crew;
        crew = 0;
    }
    
    return leftovers;
}

Ship::~Ship() {}