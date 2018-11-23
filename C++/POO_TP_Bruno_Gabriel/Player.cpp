#include "Player.h"

Player::Player() {}

Player::Player(string n)
{
    name = new string(n);
    money = 1000;
    fPorts = 0;
    nShips = fleet.size();
    MainHarbor = nullptr;
}

Player::Player(const Player& orig)
{
    name = new string(orig.getName());
    money = orig.money;
    fPorts = orig.fPorts;
    nShips = orig.nShips;
    MainHarbor = orig.MainHarbor;
}

bool Player::newShip(char t)
{
    int id;
    int yy, xx;
    istringstream is;
    
    is.str(MainHarbor->getCoord());
    is >> xx;
    is >> yy;
    
    if(fleet.size() < 100)
    {
        if(fleet.empty())
        {
            fleet.push_back(Ship(1, t));
            fleet.begin()->setCoord(yy, xx);
            return true;
        }
        else
        {
            for(id=0; id<fleet.size(); id++)
            {
                if((id+1) != fleet[id].getId())
                {
                    Ship a(id+1, t);
                    a.setCoord(yy, xx);
                    auto it = fleet.begin();
                    it += id;
                    fleet.insert(it, a);
                    return true;
                }
            }
            Ship a(id+1, t);
            a.setCoord(yy, xx);
            fleet.push_back(a);
            return true;
        }
    }
    else
        return false;
}

bool Player::sellShip(int id)
{
    char t;
    for(int i=0; i<fleet.size(); i++)
    {
        if(fleet[i].getId() == id)
        {
            auto it = fleet.begin() + i;
            t = fleet[i].getType();
            fleet.erase(it);
            switch(t)
            {
                case 'V':
                    money += PRICE_SAILBOAT;
                    break;
                case 'F':
                    money += PRICE_FRIGATE;
                    break;
                case 'G':
                    money += PRICE_GALEON;
                    break;
                case 'E':
                    money += PRICE_SCHOONER;
                    break;
                default:
                    money += PRICE_SPECIAL;
                    break;
            }
            
            return true;
        }
    }
    return false;
}

string Player::getName() const
{
    return *name;
}

int Player::getMoney() const
{
    return money;
}

void Player::setMoney(int n)
{
    money = n;
}

void Player::addMoney(int n)
{
    money += n;
}

void Player::setMainHarbor(const Harbor &main)
{
    MainHarbor = &main;
}

Harbor Player::getMainHarbor() const
{
    return *MainHarbor;
}

Player& Player::operator =(const Player& orig)
{
    if(this == &orig)
        return *this;
    
    delete name;
    name = new string(orig.getName());
    money = orig.money;
    fPorts = orig.fPorts;
    nShips = orig.nShips;
    MainHarbor = orig.MainHarbor;
}

Player::~Player()
{
    delete name;
}