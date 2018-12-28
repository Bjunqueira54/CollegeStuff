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
	    //fleet.push_back(new Sailboat(this, id, x, y));
            fleet.insert(it, new Sailboat(this, id, x, y));
	    return 0;
	case 2:
	    //fleet.push_back(new Galeon(this, id, x, y));
            fleet.insert(it, new Galeon(this, id, x, y));
	    return 0;
	case 3:
	    //fleet.push_back(new Schooner(this, id, x, y));
            fleet.insert(it, new Schooner(this, id, x, y));
	    return 0;
	case 4:
	    //fleet.push_back(new Frigate(this, id, x, y));
            fleet.insert(it, new Frigate(this, id, x, y));
	    return 0;
	case 5:
	    //fleet.push_back(new Special(this, id, x, y));
            fleet.insert(it, new Special(this, id, x, y));
	    return 0;
	default:
	    return -1;
    }
}

void Player::sellShip(int id)
{
    
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

Player::~Player() {}