#include "Ship.h"
#include "Player.h"

Ship::Ship()
{
    id = maxwater = maxcrew = maxload = moves = new int(0);
    type = new char('\0');
    
    owner = nullptr;
    
    water = crew = fish = cargo = movesl = y = dy = x = dx = 0;
    inHarbor = Moving = false;
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
    movesl = *moves;
    

    istringstream is;
    is.str(owner->getMainHarborCoord());
    is >> y;
    is >> x;
    dy = y;
    dx = x;
    inHarbor = true;
    Moving = false;
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
    movesl = orig.GetMovesl();
    
    istringstream is;
    is.str(orig.GetCoord());
    is >> y;
    is >> x;
    
    istringstream ds;
    ds.str(orig.GetDest());
    is >> dy;
    is >> dx;
    
    inHarbor = orig.IsInHarbor();
    Moving = orig.IsMoving();
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
    movesl = orig.GetMovesl();
    
    istringstream is;
    is.str(orig.GetCoord());
    is >> y;
    is >> x;
    
    istringstream ds;
    ds.str(orig.GetDest());
    is >> dy;
    is >> dx;
    
    inHarbor = orig.IsInHarbor();
    Moving = orig.IsMoving();
}

string Ship::GetCoord() const
{
    ostringstream os;
    os << y << " " << x;
    return os.str();
}

string Ship::GetDest() const
{
    ostringstream os;
    os << dy << " " << dx;
    return os.str();
}

void Ship::setDest(int yy, int xx)
{
    dy = yy;
    dx = xx;
}

void Ship::setMovesl(int n)
{
    movesl = movesl - n;
}

void Ship::turnSet()
{
    y = dy;
    x = dx;
    movesl = *moves;
    if(water > 0)
        water -= crew;
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