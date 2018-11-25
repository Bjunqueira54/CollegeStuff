#include "Player.h"
#include "Functions.h"

Player::Player()
{
    name = new string("");
    money = 0;
    fleet.push_back(nullptr);
    MainHarbor = nullptr;
}

Player::Player(string n)
{
    name = new string(n);
    money = 0;
    fleet.push_back(nullptr);
    MainHarbor = nullptr;
}

Player::Player(const Player& orig)
{
    delete name;
    name = new string(orig.GetName());
    
    money = orig.GetMoney();
    MainHarbor = orig.getMainHarbor();
}

Player& Player::operator=(const Player& orig)
{
    if(this == &orig)
        return *this;
    
    delete name;
    name = new string(orig.GetName());
    
    money = orig.GetMoney();
    MainHarbor = orig.getMainHarbor();
}

const string Player::getMainHarborCoord() const
{
    return MainHarbor->getCoord();
}

Harbor* Player::getMainHarbor() const
{
    return MainHarbor;
}

Ship* Player::newShip(char t)
{
    if(MainHarbor == nullptr)
        return nullptr;
    
    int id;
    
    if(fleet[0] == nullptr)
    {
        fleet[0] = new Ship(1, t, *this);
        
        return fleet[0];
    }
    
    for(id=0; id<fleet.size(); id++)
    {
        if((id+1) != fleet[id]->GetId())
        {
            auto it = fleet.begin() + id;
            fleet.insert(it, new Ship(id+1, t, *this));
            return fleet[id];
        }
    }
    fleet.push_back(new Ship(id+1, t, *this));
    return fleet[id];
}

bool Player::sellShip(int id)
{
    for(int i=0; i<fleet.size(); i++)
    {
        if(fleet[i]->GetId() == id)
        {
            if(fleet[i]->IsInHarbor() == true)
            {
                auto it = fleet.begin() + i;
                fleet.erase(it);
                return true;
            }
            else
                return false;
        }
    }
    return false;
}

void Player::turnSet()
{
    for(int i=0; i<fleet.size(); i++)
        fleet[i]->turnSet();
}

Player::~Player()
{
    delete name;
}