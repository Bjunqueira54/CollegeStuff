#include "Player.h"

Player::Player() {}

Player::Player(const Player& orig) {}

Player::Player(string n, int m, Harbor* h):name(n), money(m)
{
    mainharbor = h;
}

int Player::buyShip(int type)
{
    int x, y, i, id;
    istringstream is;
    is.str(mainharbor->getCoord());
    is >> x;
    is >> y;
    
    for(i=0; i<fleet.size(); i++)
    {
        if(i+1 != fleet[i]->getID())
        {
            id = i + 1;
            break;
        }
    }
    
    auto it = fleet.begin() + i;
    
    switch(type)
    {
	case 1:
            fleet.insert(it, new Sailboat(this, id, x, y));
	    return 0;
	case 2:
            fleet.insert(it, new Galeon(this, id, x, y));
	    return 0;
	case 3:
            fleet.insert(it, new Schooner(this, id, x, y));
	    return 0;
	case 4:
            fleet.insert(it, new Frigate(this, id, x, y));
	    return 0;
	case 5:
            fleet.insert(it, new Special(this, id, x, y));
	    return 0;
	default:
	    return -1;
    }
}

int Player::sellShip(int id)
{
    for(int i=0; i<fleet.size(); i++)
    {
        if(fleet[i]->getID() == id)
        {
            auto it = fleet.begin() + i;
            delete fleet[i];
            fleet.erase(it);
            return 0;
        }
    }
    
    return -1;
}

int Player::spawnship(int type, int x, int y)
{
    int id, i;
    
    for(i=0; i<fleet.size(); i++)
    {
        if(i+1 != fleet[i]->getID())
        {
            id = i + 1;
            break;
        }
    }
    
    auto it = fleet.begin() + i;
    
    if(type == 1)
    {
	fleet.insert(it, new Sailboat(this, id, x, y));
	return 0;
    }
    else if(type == 4)
    {
	fleet.insert(it, new Frigate(this, id, x, y));
	return 0;
    }
    else
	return -1;
	
}

const int Player::getCrew(int id) const
{
    for(int i=0; i<fleet.size(); i++)
    {
        if(id == fleet[i]->getID())
            return fleet[i]->getCrew();
    }
}

const int Player::getCargo(int id) const
{
    for(int i=0; i<fleet.size(); i++)
    {
        if(id == fleet[i]->getID())
            return fleet[i]->getCargo();
    }
}

const int Player::getFish(int id) const
{
    for(int i=0; i<fleet.size(); i++)
    {
        if(id == fleet[i]->getID())
            return fleet[i]->getFish();
    }
}

const string Player::getShipCoord(int i) const
{
    if(i < fleet.size())
        return fleet[i]->getCoord();
}

const string Player::getShipCoordByID(int id) const
{
    for(auto& it: fleet)
    {
        if(it->getID() == id)
            return it->getCoord();
    }
}

const bool Player::getShipInHarbor(int i) const
{
    if(i < fleet.size())
        return fleet[i]->isInHarbor();
}

const int Player::getShipType(int i) const
{
    if(i < fleet.size())
        return fleet[i]->getType();
}

const string Player::getShipID(int i) const
{
    if(i < fleet.size())
    {
        int id;
        ostringstream os;
        
        id = fleet[i]->getID();
        
        if(id < 10)
        {
            os << "0" << id;
        }
        else
            os << id;
        
        return os.str();
    }
}

int Player::ShipMove(int id, string dir)
{
    for(auto& it: fleet)
    {
        if(it->getID() == id)
        {
            it->move(dir);
        }
    }
}

Player::~Player()
{
    for(auto& it: fleet)
    {
        delete it;
        it = nullptr;
    }
}