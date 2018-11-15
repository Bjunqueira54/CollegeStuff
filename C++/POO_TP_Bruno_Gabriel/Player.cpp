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
    int id;
    while(1)
    {
        id = rid(rng);
        
        for(const auto &it: fleet)
        {
            if( ! (id == it.getId() ) )
                fleet.push_back(Ship(id, t));
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