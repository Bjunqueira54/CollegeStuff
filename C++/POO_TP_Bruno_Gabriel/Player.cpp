#include <random>
#include <ctime>
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

/*bool Player::NewShip(char t)    //New Ship is created with a random [1;99] id. DON'T LOOK AT THIS, IT'S SHAMEFUL!
{
    mt19937 rng(time(NULL));
    uniform_int_distribution<int> rid(1, 99);
    int id, exists=0;
    while(1)
    {
        id = rid(rng);
        
        for(int i=0; i<fleet.size(); i++)
        {
            if(id == fleet[i].getId())
                exists = 1;
        }
        if(exists == 0)
        {
            fleet.push_back(Ship(id, t));
            istringstream is;
            int sy, sx;
            is >> sy;
            is >> sx;
            is.str(MainHarbor->getCoord());
            fleet[fleet.size()-1].setCoord(sy, sx);
            return true;
        }
    }
}*/

bool Player::newShip(char t)
{
    int id;
    int yy, xx;
    istringstream is;
    /*is.str(MainHarbor->getCoord());
    is >> xx;
    is >> yy;*/
    
    xx=1;
    yy=1;
    
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

void Player::setMainHarbor(const Harbor& main)
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