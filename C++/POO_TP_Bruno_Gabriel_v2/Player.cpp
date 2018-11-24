#include "Player.h"
#include "Harbor.h"

Player::Player()
{
    name = new string("");
    money = 0;
    fleet.push_back(nullptr);
}

Player::Player(string n)
{
    name = new string(n);
    money = 0;
    fleet.push_back(nullptr);
}

Player::Player(const Player& orig)
{
    delete name;
    name = new string(orig.GetName());
    
    money = orig.GetMoney();
}

Player& Player::operator=(const Player& orig)
{
    if(this == &orig)
        return *this;
    
    delete name;
    name = new string(orig.GetName());
    
    money = orig.GetMoney();
}

const string Player::getMainHarborCoord() const
{
    return MainHarbor->getCoord();
}

void Player::newShip(char t)
{
    int id;
    
    if(fleet[0] == nullptr)
    {
        fleet[0] = new Ship(1, t, *this);
        
        return;
    }
    
    for(id=0; id<fleet.size(); id++)
    {
        if((id+1) != fleet[id]->GetId())
        {
            auto it = fleet.begin() + id;
            fleet.insert(it, new Ship(id, t, *this));
            return;
        }
    }
    fleet.push_back(new Ship(id, t, *this));
    return;
}

Player::~Player()
{
    delete name;
}