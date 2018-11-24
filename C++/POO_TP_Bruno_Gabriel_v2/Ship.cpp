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
    
    if(t == 'V' || t == 'v')
    {
        type = new char('V');
        maxwater = new int(200);
        maxcrew = new int(20);
        maxload = new int(40);
        moves = new int(2);
    }
    else if(t == 'G' || t == 'g')
    {
        type = new char('G');
        maxwater = new int(400);
        maxcrew = new int(40);
        maxload = new int(70);
        moves = new int(1);
    }
    else if(t == 'E' || t == 'e')
    {
        type = new char('E');
        maxwater = new int(100);
        maxcrew = new int(10);
        maxload = new int(20);
        moves = new int(1);
    }
    else if(t == 'F' || t == 'f')
    {
        type = new char('F');
        maxwater = new int(500);
        maxcrew = new int(50);
        maxload = new int(0);
        moves = new int(2);
    }
    else
    {
        type = new char('S');
        maxwater = new int(1000);
        maxcrew = new int(300);
        maxload = new int(150);
        moves = new int(5);
    }
    
    owner = &p;
    
    water = *maxwater;
    crew = *maxcrew;
    fish = 0;
    cargo = 0;
    

    istringstream is;
    is.str(owner->getMainHarborCoord());
    is >> y;
    is >> x;
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
    
    istringstream is;
    is.str(orig.GetCoord());
    is >> y;
    is >> x;
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