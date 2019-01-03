#include "Player.h"

Player::Player() {}

Player::Player(const Player& orig) {}

Player::Player(string n, int m, Harbor* h):name(n), money(m) { mainharbor = h; }

void Player::setMoney(int n)
{
    if(n > 0)
        money += n;
    else
        money -= abs(n);
}

int Player::ShipSetCargo(int id, int cargo)
{
    for(auto& it: fleet)
    {
        if(it->getID() == id)
        {
            return it->addCargo(cargo);
        }
    }
    
    return -1;
}

int Player::ShipSetCrew(int id, int crew)
{
    for(auto& it: fleet)
    {
        if(it->getID() == id)
        {
            return it->addCrew(crew);
        }
    }
    
    return -1;
}

int Player::ShipSetFish(int id, int fish)
{
    for(auto& it: fleet)
    {
        if(it->getID() == id)
        {
            return it->addFish(fish);
        }
    }
        
    return -1;
}

int Player::buyShip(int type)
{
    int x, y, i, id;
    istringstream is;
    is.str(mainharbor->getCoord());
    is >> y;
    is >> x;
    
    for(i=0; i<fleet.size(); i++)
    {
        if(i+1 != fleet[i]->getID())
            break;
    }
    
    id = i + 1;
    auto it = fleet.begin() + i;
    
    switch(type)
    {
	case 1:
            fleet.insert(it, new Sailboat(this, id, y, x, true));
	    return 0;
	case 2:
            fleet.insert(it, new Galeon(this, id, y, x));
	    return 0;
	case 3:
            fleet.insert(it, new Schooner(this, id, y, x));
	    return 0;
	case 4:
            fleet.insert(it, new Frigate(this, id, y, x, true));
	    return 0;
	case 5:
            fleet.insert(it, new Special(this, id, y, x));
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

int Player::spawnship(int type, int x, int y, bool sih)
{
    int id, i;
    
    for(i=0; i<fleet.size(); i++)
    {
        if(i+1 != fleet[i]->getID())
            break;
    }
    
    id = i + 1;
    
    auto it = fleet.begin() + i;
    
    if(type == 1)
    {
	fleet.insert(it, new Sailboat(this, id, y, x, sih));
	return 0;
    }
    else if(type == 4)
    {
	fleet.insert(it, new Frigate(this, id, y, x, sih));
	return 0;
    }
    else
	return -1;
}

const int Player::getCrew(int id) const
{
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->getCrew();

    return -1;
}

const int Player::getCargo(int id) const
{
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->getCargo();

    return -1;
}

const int Player::getFish(int id) const
{
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->getFish();

    return -1;
}

const string Player::getShipCoord(int id) const
{
    for(auto& it: fleet)
    {
        if(it->getID() == id)
            return it->getCoord();
    }
    
    return "";
}

const string Player::getShipDestCoord(int id) const
{
    for(auto& it: fleet)
    {
        if(it->getID() == id)
        {
            return it->getDestCoord();
        }
    }
    
    return "";
}

const string Player::getShipInfo(int id) const
{
    for(auto& it: fleet)
    {
        if(it->getID() == id)
            return it->getShipInfo();
    }
    
    return "";
}

const bool Player::getShipSpecMoving(int id) const
{
    //Iterator to look for a ship with matching ID numbers. If found, returns it's state.
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->isSpecMoving();
    
    //In case a ship with <id> doesn't exist, returns true. Troubleshooting for wrong id number in
    //the case of the ship's bool vars would be for them to be all true.
    //In other words, if all of the bool vars of a certain ship <id> are true, then something is wrong.
    return true;   
}

const bool Player::getShipInHarbor(int id) const
{
    //Iterator to look for a ship with matching ID numbers. If found, returns it's state.
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->isInHarbor();
    
    //Even if no ship exists with that ID, we don't want the map to draw non-existant data, so just give back "true"
    return true;    
}

const bool Player::getShipStopped(int id) const
{
    //Iterator to look for a ship with matching ID numbers. If found, returns it's state.
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->isStopped();
    
    //In case a ship with <id> doesn't exist, returns true. Troubleshooting for wrong id number in
    //the case of the ship's bool vars would be for them to be all true.
    //In other words, if all of the bool vars of a certain ship <id> are true, then something is wrong.
    return true;   
}

const bool Player::getShipIsFull(int id) const
{
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->isFull();
}

const bool Player::getShipAuto(int id) const
{
    //Iterator to look for a ship with matching ID numbers. If found, returns it's state.
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->isAuto();
    
    //In case a ship with <id> doesn't exist, returns true. Troubleshooting for wrong id number in
    //the case of the ship's bool vars would be for them to be all true.
    //In other words, if all of the bool vars of a certain ship <id> are true, then something is wrong.
    return true;   
}

const int Player::getShipCargo(int id) const
{
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->getCargo();
    
    return -1;
}

const int Player::getShipFish(int id) const
{
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->getFish();
    
    return -1;
}

const bool Player::CoordExists(string coord) const
{
    for(auto& it: fleet)
    {
        if(it->getCoord() == coord)
            return true;
    }
    
    return false;
}

const int Player::getShipMoves(int id) const
{
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->getMoves();
    
    //If a ship with that ID number doesn't exist, return the general error value of -1
    return -1;  
}

const int Player::getShipWater(int id) const
{
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->getWater();
    
    return -1;
}

const int Player::getShipType(int id) const
{
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->getType();
    
    //If a ship with that ID number doesn't exist, return the general error value of -1
    return -1;        
}

const int Player::getShipID(int i) const
{
    if(i < fleet.size())
        return fleet[i]->getID();
    
    return -1;
}

int Player::ShipSetDestination(int id, string destCoord, bool isDestHarbor)
{
    for(auto& it: fleet)
    {
        if(it->getID() == id)
        {
            istringstream is;
            int y, x;
            
            is.str(destCoord);
            
            is >> y;
            is >> x;
            
            return it->setDestination(y, x, isDestHarbor);
        }
    }
    
    return -1;
}

int Player::ShipSetAuto(int id)
{
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->SetAuto();
}

int Player::ShipMove(int id, int yy, int xx)
{
    for(auto& it: fleet)
    {
        if(it->getID() == id)
        {
            it->move(yy, xx);
            return 0;
        }
    }
    
    return -1;
}

int Player::ShipStop(int id)
{
    for(auto& it: fleet)
        if(it->getID() == id)
            it->Stop();
}

void Player::toggleShipSpecMoving(int id)
{
    for(auto& it: fleet)
        if(it->getID() == id)
        {
            it->toggleSpecMoving();
            return;
        }
    
    return;
}

void Player::toggleShipInHarbor(int id)
{
    for(auto& it: fleet)
        if(it->getID() == id)
        {
            it->toggleInHarbor();
            return;
        }
    
    return;
}

void Player::toggleShipAuto(int id)
{
    for(auto& it: fleet)
        if(it->getID() == id)
        {
            it->toggleAuto();
            return;
        }

    return;
}

const int Player::getShipmaxCrew(int id) const
{
    for(auto& it: fleet)
        if(it->getID() == id)
            return it->getMaxcrew();

    return -1;
}

const int Player::ShipFish(int id) const
{
    for(auto &it: fleet)
        if(it->getID() == id)
            return it->Fish();
    
    return -1;
}

Player::~Player()
{
    for(auto& it: fleet)
    {
        delete it;
        it = nullptr;
    }
}