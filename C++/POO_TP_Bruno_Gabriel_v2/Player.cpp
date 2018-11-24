#include "Player.h"

Player::Player()
{
    name = new string("");
    money = 0;
}

Player::Player(string n)
{
    name = new string(n);
    money = 0;
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

Player::~Player()
{
    delete name;
}