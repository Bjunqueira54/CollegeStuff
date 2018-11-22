#include <random>
#include <ctime>
#include "Player.h"

Player::Player() {}

Player::Player(string n)
{
    name = new string(n);
    money = 1000;
}

/*bool Player::NewShip(char t)    //Random ID
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

bool Player::NewShip(char t)
{
    int id;
    int yy, xx;
    istringstream is;
    
    if(fleet.size() < 100)
    {
        if(fleet.empty())
        {
            fleet.push_back(Ship(1, t));
            is.str(fleet.begin()->getCoord());
            is >> xx;
            is >> yy;
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
                    is.str(a.getCoord());
                    is >> xx;
                    is >> yy;
                    a.setCoord(yy, xx);
                    auto it = fleet.begin();
                    it += id;
                    fleet.insert(it, a);
                    return true;
                }
            }
            Ship a(id+1, t);
            is.str(a.getCoord());
            is >> xx;
            is >> yy;
            a.setCoord(yy, xx);
            fleet.push_back(a);
            return true;
        }
    }
    else
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

/*void Player::setMainHarbor(const Harbor& main)
{
}*/

Player& Player::operator =(const Player& orig)
{
    delete name;
    name = new string(orig.getName());
}

Player::~Player()
{
    delete name;
}