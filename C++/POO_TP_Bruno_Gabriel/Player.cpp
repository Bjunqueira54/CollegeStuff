#include "Player.h"

Player::Player(string n): name(n)
{
    money = 1000;
}

bool Player::NewShip(char t)
{
    
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