#include "Ship.h"
#include "Player.h"

Ship::Ship()
{
    id = new int(0);
    type = new char('\0');
    
    maxwater = new int(0);
    maxcrew = new int(0);
    maxload = new int(0);
    moves = new int(0);
    
    owner = nullptr;
    
    water = 0;
    crew = 0;
    fish = 0;
    cargo = 0;
    
    y=0;
    x=0;
}

Ship::Ship(int i, char t, Player& p)
{
    id = new int(i);
    type = new char(t);
    
    maxwater = new int(0);
    maxcrew = new int(0);
    maxload = new int(0);
    moves = new int(0);
    
    owner = &p;
    
    water = *maxwater;
    crew = *maxcrew;
    fish = 0;
    cargo = 0;
    
    /*OWNER MAIN HARBOR!
    istringstream is;
    is.str(owner->getMainHarborCoord());
    is >> y;
    is >> x;
    */ //Perfect!
}

Ship::Ship(const Ship& orig)
{
    delete id;
    delete type;
    delete maxwater;
    delete maxcrew;
    delete maxload;
    delete moves;
    
    id = new int(orig.GetId());
    type = new char(orig.GetType());
    maxwater = new int(orig.GetMaxwater());
    maxcrew = new int(orig.GetMaxcrew());
    maxload = new int(orig.GetMaxload());
    moves = new int(orig.GetMoves());
    
    owner = orig.getOwner();
    
    water = orig.GetWater();
    crew = orig.GetCrew();
    fish = orig.GetFish();
    cargo = orig.GetCargo();
}

Ship& Ship::operator =(const Ship& orig)
{
    if(this == &orig)
        return *this;
    
    delete id;
    delete type;
    delete maxwater;
    delete maxcrew;
    delete maxload;
    delete moves;
    
    id = new int(orig.GetId());
    type = new char(orig.GetType());
    maxwater = new int(orig.GetMaxwater());
    maxcrew = new int(orig.GetMaxcrew());
    maxload = new int(orig.GetMaxload());
    moves = new int(orig.GetMoves());
    
    owner = orig.getOwner();
    
    water = orig.GetWater();
    crew = orig.GetCrew();
    fish = orig.GetFish();
    cargo = orig.GetCargo();
}

string Ship::GetCoord() const
{
    ostringstream os;
    os << y << " " << x;
    return os.str();
}

Ship::~Ship()
{
    delete id;
    delete type;
    delete maxwater;
    delete maxcrew;
    delete maxload;
    delete moves;
}