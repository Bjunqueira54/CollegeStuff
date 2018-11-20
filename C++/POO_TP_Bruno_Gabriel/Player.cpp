#include <random>
#include <ctime>
#include "Player.h"

Player::Player(string n): name(n)
{
    money = 1000;
}

bool Player::NewShip(char t)
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
}

string Player::getName() const
{
    return name;
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