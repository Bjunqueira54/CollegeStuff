#include "Player.h"

Player::Player() {}

Player::Player(const Player& orig) {}

Player::Player(string n, int m):name(n), money(m) {}

int Player::buyShip(int type)
{
    int x, y;
    istringstream is;
    is.str(mainharbor->getCoord());
    is >> x;
    is >> y;
    
    switch(type)
    {
	case 1:
	    fleet.push_back(new Sailboat(this, x, y));
	    return 0;
	case 2:
	    fleet.push_back(new Galeon(this, x, y));
	    return 0;
	case 3:
	    fleet.push_back(new Schooner(this, x, y));
	    return 0;
	case 4:
	    fleet.push_back(new Frigate(this, x, y));
	    return 0;
	case 5:
	    fleet.push_back(new Special(this, x, y));
	    return 0;
	default:
	    return -1;
    }
}

int Player::spawnship(int type, int x, int y)
{
    if(type == 1)
    {
	fleet.push_back(new Sailboat(this, x, y));
	return 0;
    }
    else if(type == 4)
    {
	fleet.push_back(new Frigate(this, x, y));
	return 0;
    }
    else
	return -1;
	
}


Player::~Player() {}